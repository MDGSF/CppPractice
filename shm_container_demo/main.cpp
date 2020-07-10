#include <stdio.h>

#include <iostream>
#include <thread>

#include "shmc/posix_shm_alloc.h"
#include "shmc/shm_sync_buf.h"

using namespace shmc;

constexpr const char* kShmKey = "0x10005";
constexpr size_t kSyncBufSize = 1024 * 1024 * 100;

POSIX p;
shmc::ShmSyncBuf<POSIX> sync_buf_w;
shmc::ShmSyncBuf<POSIX> sync_buf_r;

void Thread1() {
  char acMsg[1024] = {0};
  for (int i = 0; i <= 10000; i++) {
    sprintf(acMsg, "hello_%d", i);
    printf("write loop: %s\n", acMsg);
    if (sync_buf_w.Push(acMsg, strlen(acMsg) + 1)) {
    } else {
      printf("write failed\n");
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
  }
}

void Thread2(int tid) {
  int iRet = 0;
  uint64_t iPreSeq = 0;
  shmc::SyncIter it = sync_buf_r.Head();
  char buf[1024] = {0};
  size_t len = sizeof(buf);
  shmc::SyncMeta meta;
  while (true) {
    iRet = sync_buf_r.Read(it, &meta, buf, &len);
    if (iRet < 0) {
      printf("read failed, iRet = %d\n", iRet);
    } else if (iRet == 0) {
      // printf("read loop iRet == 0\n");
    } else {
      if (meta.seq != iPreSeq) {
        iPreSeq = meta.seq;
        printf("[%d]: [%lu %lu %lu], %s\n", tid, meta.seq, meta.time.tv_sec,
               meta.time.tv_usec, buf);

        sync_buf_r.Next(&it);
      }
    }
  }
}

int main() {
  printf("Hello World\n");

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