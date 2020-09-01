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

### Step12

```bash
cd Step12
mkdir debug
mkdir release
```

```txt
- Step12
    - debug
    - release
```

```bash
cd debug
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build .
cd ../release
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
```

