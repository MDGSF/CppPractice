# cmake tutorial

https://cmake.org/cmake/help/latest/guide/tutorial/index.html#cmake-tutorial

```
CMake/Help/guide/tutorial
```

### Step1

```bash
mkdir Step1_build
cd Step1_build
cmake ../Step1
cmake --build .
```

### Step2

```bash
mkdir Step2_build
cd Step2_build
cmake ../Step2
cmake --build .
```

```bash
mkdir Step2_build
cd Step2_build
cmake -DUSE_MYPATH=off ../Step2
cmake --build .
```

