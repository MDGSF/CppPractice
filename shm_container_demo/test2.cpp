#include <stdio.h>
#include <sys/time.h>

#include <iostream>
#include <thread>

#include "shmc/posix_shm_alloc.h"
#include "shmc/shm_sync_buf_spmc.h"
using namespace shmc::shm_sync_buf_spmc;

// #include "shmc/shm_sync_buf.h"
// using namespace shmc;

constexpr const char* kShmKey = "0x10005";
constexpr size_t kSyncBufSize = 1024 * 1024 * 32;

shmc::POSIX p;
ShmSyncBuf<shmc::POSIX> sync_buf_w;
ShmSyncBuf<shmc::POSIX> sync_buf_r;

void gen_random(char* s, const int len) {
  static const char alphanum[] =
      "0123456789"
      "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
      "abcdefghijklmnopqrstuvwxyz";

  for (int i = 0; i < len; ++i) {
    s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
  }

  s[len] = 0;
}

void Thread1() {
  printf("Thread Write start\n");
  for (uint16_t i = 0;; i++) {
    char acMsg[2048] = {0};
    char acRandom[1024] = {0};
    int iRandonNumber = rand() % (sizeof(acRandom) - 1);
    gen_random(acRandom, iRandonNumber);
    sprintf(acMsg, "%d: %s", i, acRandom);

    timeval ts{time(nullptr), 0};

    if (i % 1000 == 0) {
      printf("write loop: [%lu] %s\n", ts.tv_sec, acMsg);
    }

    if (!sync_buf_w.Push(acMsg, strlen(acMsg) + 1, ts)) {
      printf("write failed\n");
      exit(-1);
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }
  printf("Thread Write end\n");
}

void Thread2(int tid) {
  int iRet = 0;
  uint64_t iPreSeq = 0;
  SyncIter it = sync_buf_r.Head();
  int iPreBufIdx = -1;

  while (true) {
    SyncMeta meta;
    iRet = sync_buf_r.Read(&it, &meta);
    if (iRet < 0) {
      printf("read failed, iRet = %d\n", iRet);
      exit(-1);
    } else if (iRet == 0) {
      // printf("read loop iRet == 0\n");
    } else {
      char buf[2048] = {0};
      size_t buf_len = sizeof(buf);
      size_t data_len = meta.len;
      size_t copy_len = (data_len < buf_len ? data_len : buf_len);
      memcpy(buf, meta.data, copy_len);

      if (iPreBufIdx % 5000 == 0) {
        printf("[%02d]: [%lu %lu %lu], [%zu] %s\n", tid, meta.seq,
               meta.time.tv_sec, meta.time.tv_usec, data_len, buf);
      }

      char* pcIdx = strstr(buf, ":");
      *pcIdx = 0;
      int iCurBufIdx = atoi(buf);
      *pcIdx = ':';

      if (iCurBufIdx > iPreBufIdx || (iPreBufIdx == 65535 && iCurBufIdx == 0)) {
        iPreBufIdx = iCurBufIdx;
      } else {
        printf(
            "[%02d]: [%lu %lu %lu], [%zu] %s, iPreBufIdx = %d, iCurBufIdx = "
            "%d\n",
            tid, meta.seq, meta.time.tv_sec, meta.time.tv_usec, data_len, buf,
            iPreBufIdx, iCurBufIdx);
        exit(-1);
      }

      sync_buf_r.Next(&it);
    }
  }
}

void log_func(shmc::LogLevel level, const char* data) {
  printf("[%d]: %s\n", level, data);
}

int main() {
  printf("Hello World\n");

  shmc::SetLogHandler(shmc::kWarning, log_func);

  p.Unlink(kShmKey);
  sync_buf_w.InitForWrite(kShmKey, kSyncBufSize);
  sync_buf_r.InitForRead(kShmKey);

  std::thread myThreads[100];
  for (int i = 0; i < 100; i++) {
    myThreads[i] = std::thread(Thread2, i);
  }
  std::thread t1(Thread1);

  t1.join();
  for (int i = 0; i < 100; i++) {
    myThreads[i].join();
  }

  return 0;
}