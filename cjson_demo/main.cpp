#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"

int main() {
  cJSON* obj = cJSON_CreateObject();

  cJSON_AddStringToObject(obj, "message", "create user success");

  //char *out = cJSON_Print(obj);
  char *out = cJSON_PrintUnformatted(obj);

  printf("%s\n", out);

  free(out);

  cJSON_Delete(obj);

  return 0;
}
