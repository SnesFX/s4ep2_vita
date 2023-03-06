# THIS SHIT DOES NOT WORK! JUST OPEN SOURCING IT BECAUSE I SAID I WOULD ON TWITTER LMAO!

* Reason why it doesn't work: Not able to extract obb file because of the way it was compressed.

# Sonic 4 Episode 2 Wrapper/Port for PS Vita

This repository contains a loader of **the Android release of Sonic 4 Episode 2**, using
the [GTASA Vita Port](https://github.com/TheOfficialFloW/gtasa_vita) as the base.
The loader provides a tailored, minimalistic Android-like environment to run
the official ARMv7 game executables on PS Vita.

**This software does not contain the original code, executables, assets, or other
non redistributable parts of the game. The authors do not promote or condone piracy
in any way. To launch and play the game on their PS Vita device, users must provide
their own legally obtained copy of the game in the form of an .apk file.**

## Setup Instructions (For End Users)

In order to properly install the game, you'll have to follow these steps precisely:

- Install [kubridge](https://github.com/TheOfficialFloW/kubridge/releases/) and [FdFix](https://github.com/TheOfficialFloW/FdFix/releases/) by copying `kubridge.skprx` and `fd_fix.skprx` to your taiHEN plugins folder (usually `ur0:tai`) and adding two entries to your `config.txt` under `*KERNEL`:
 
```
  *KERNEL
  ur0:tai/kubridge.skprx
  ur0:tai/fd_fix.skprx
```

**Note** Don't install fd_fix.skprx if you're using the rePatch plugin!


- <u>Legally</u> obtain your copy of Sonic 4 Episode 2
for Android in form of an `.apk` file and `.obb` file (`main.10050073.com.sega.sonic4ep2.obb` is located inside the `/sdcard/android/obb/com.sega.sonic4ep2/`) folder. [You can get all the required files directly from your phone](https://stackoverflow.com/questions/11012976/how-do-i-get-the-apk-of-an-installed-app-without-root-access) or by using any APK extractor you can find on Google Play.
- Open the `.apk` with any zip explorer (like [7-Zip](https://www.7-zip.org/)) and extract it. Copy `libfox.so` file (located in the lib/armeabi-v7a folder inside the apk) into `ux0:data/s4ep2/`.
- Open the `main.10050073.com.sega.sonic4ep2.obb` with your zip explorer (.obb files are zip files just like .apk files so just rename the .obb to .zip) and extract the contents to `ux0:data/s4ep2/`.
- Install `S4EP2.vpk` (from [Releases](https://github.com/SnesFX/s4ep2-vita/releases/latest)).

## Build Instructions (For Developers)

In order to build the loader, you'll need a [vitasdk](https://github.com/vitasdk) build fully compiled with softfp usage.  
You can find a precompiled version here: [Linux](https://github.com/vitasdk/buildscripts/suites/1824103476/artifacts/35161735) / [Windows](https://github.com/vitasdk/buildscripts/suites/1836262288/artifacts/35501612).  
Additionally, you'll need these libraries to bee compiled as well with `-mfloat-abi=softfp` added to their CFLAGS:

- [openal-soft](https://github.com/isage/openal-soft/tree/vita-1.19.1)
- [libmathneon](https://github.com/Rinnegatamante/math-neon)
- [vitaShaRK](https://github.com/Rinnegatamante/vitaShaRK)
- [imgui-vita](https://github.com/Rinnegatamante/imgui-vita)
- [kubridge](https://github.com/TheOfficialFloW/kubridge)

As last requirement, you'll need to compile [vitaGL](https://github.com/Rinnegatamante/vitaGL) with `make HAVE_SBRK=1 HAVE_SHARK=1 SOFTFP_ABI=1 SHARED_RENDERTARGETS=1 NO_DEBUG=1 install`.  
After all these requirements are met, you can compile the loader with the following commands:

```
mkdir build && cd build
cmake -G "Unix Makefiles" ..
make
```

## Credits

- [TheOfficialFloW](https://github.com/TheOfficialFloW/) for the original .so loader.
- [GrapheneCt](https://github.com/GrapheneCt) for the PVR_PSP2, gpu_es4_kernel_ext and lots of tips.
- [TheOfficialFloW](https://github.com/TheOfficialFloW/), [Rinnegatamante](https://github.com/Rinnegatamante/) and [v-atamanenko](https://github.com/v-atamanenko) for all of the previous work on Android wrapper ports.