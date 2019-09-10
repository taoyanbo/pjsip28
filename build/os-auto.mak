# build/os-auto.mak.  Generated from os-auto.mak.in by configure.

export OS_CFLAGS   := $(CC_DEF)PJ_AUTOCONF=1  -fpic -ffunction-sections -funwind-tables -no-canonical-prefixes -O2 -DNDEBUG -Ijni -DANDROID -Wa,--noexecstack -Wformat -Werror=format-security --sysroot /Users/taoyanbo/Documents/android-ndk-r14b/platforms/android-21/arch-arm64  -I/Users/taoyanbo/Documents/android-ndk-r14b/sources/cxx-stl/gnu-libstdc++/4.9/include -I/Users/taoyanbo/Documents/android-ndk-r14b/sources/cxx-stl/gnu-libstdc++/4.9/libs/arm64-v8a/include -DPJ_IS_BIG_ENDIAN=0 -DPJ_IS_LITTLE_ENDIAN=1 -I../openssl/arm64-v8a/include

export OS_CXXFLAGS := $(CC_DEF)PJ_AUTOCONF=1  -shared --sysroot=/Users/taoyanbo/Documents/android-ndk-r14b/platforms/android-21/arch-arm64 -lgcc -no-canonical-prefixes -Wl,--build-id -Wl,--no-undefined -Wl,-z,noexecstack -Wl,-z,relro -Wl,-z,now -Wl,--warn-shared-textrel -Wl,--fatal-warnings -lc -lm -fexceptions -frtti

export OS_LDFLAGS  :=  --sysroot=/Users/taoyanbo/Documents/android-ndk-r14b/platforms/android-21/arch-arm64 -L/Users/taoyanbo/Documents/android-ndk-r14b/sources/cxx-stl/gnu-libstdc++/4.9/libs/arm64-v8a/ -L../openssl/arm64-v8a/lib -lssl -lcrypto -lm -lgnustl_static  -lc -lgcc -ldl -lOpenSLES -llog -lGLESv2 -lEGL -landroid

export OS_SOURCES  := 


