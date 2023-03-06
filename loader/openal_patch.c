/* openal_patch.c -- openal redirection
 *
 * Copyright (C) 2021 Andy Nguyen
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include <stdio.h>
#include <string.h>

#define AL_ALEXT_PROTOTYPES
#include <AL/alext.h>
#include <AL/efx.h>

#include "main.h"
#include "so_util.h"

ALCcontext *alcCreateContextHook(ALCdevice *dev, const ALCint *unused) {
  // override 22050hz with 44100hz in case someone wants high quality sounds
  const ALCint attr[] = { ALC_FREQUENCY, 44100, 0 };
  return alcCreateContext(dev, attr);
}

void patch_openal(void) {
  hook_addr(so_symbol(&s4ep2_mod, "alAuxiliaryEffectSlotf"), (uintptr_t)alAuxiliaryEffectSlotf);
  hook_addr(so_symbol(&s4ep2_mod, "alAuxiliaryEffectSlotfv"), (uintptr_t)alAuxiliaryEffectSlotfv);
  hook_addr(so_symbol(&s4ep2_mod, "alAuxiliaryEffectSloti"), (uintptr_t)alAuxiliaryEffectSloti);
  hook_addr(so_symbol(&s4ep2_mod, "alAuxiliaryEffectSlotiv"), (uintptr_t)alAuxiliaryEffectSlotiv);
  hook_addr(so_symbol(&s4ep2_mod, "alBuffer3f"), (uintptr_t)alBuffer3f);
  hook_addr(so_symbol(&s4ep2_mod, "alBuffer3i"), (uintptr_t)alBuffer3i);
  hook_addr(so_symbol(&s4ep2_mod, "alBufferData"), (uintptr_t)alBufferData);
  hook_addr(so_symbol(&s4ep2_mod, "alBufferSamplesSOFT"), (uintptr_t)alBufferSamplesSOFT);
  hook_addr(so_symbol(&s4ep2_mod, "alBufferSubDataSOFT"), (uintptr_t)alBufferSubDataSOFT);
  hook_addr(so_symbol(&s4ep2_mod, "alBufferSubSamplesSOFT"), (uintptr_t)alBufferSubSamplesSOFT);
  hook_addr(so_symbol(&s4ep2_mod, "alBufferf"), (uintptr_t)alBufferf);
  hook_addr(so_symbol(&s4ep2_mod, "alBufferfv"), (uintptr_t)alBufferfv);
  hook_addr(so_symbol(&s4ep2_mod, "alBufferi"), (uintptr_t)alBufferi);
  hook_addr(so_symbol(&s4ep2_mod, "alBufferiv"), (uintptr_t)alBufferiv);
  hook_addr(so_symbol(&s4ep2_mod, "alDeferUpdatesSOFT"), (uintptr_t)alDeferUpdatesSOFT);
  hook_addr(so_symbol(&s4ep2_mod, "alDeleteAuxiliaryEffectSlots"), (uintptr_t)alDeleteAuxiliaryEffectSlots);
  hook_addr(so_symbol(&s4ep2_mod, "alDeleteBuffers"), (uintptr_t)alDeleteBuffers);
  hook_addr(so_symbol(&s4ep2_mod, "alDeleteEffects"), (uintptr_t)alDeleteEffects);
  hook_addr(so_symbol(&s4ep2_mod, "alDeleteFilters"), (uintptr_t)alDeleteFilters);
  hook_addr(so_symbol(&s4ep2_mod, "alDeleteSources"), (uintptr_t)alDeleteSources);
  hook_addr(so_symbol(&s4ep2_mod, "alDisable"), (uintptr_t)alDisable);
  hook_addr(so_symbol(&s4ep2_mod, "alDistanceModel"), (uintptr_t)alDistanceModel);
  hook_addr(so_symbol(&s4ep2_mod, "alDopplerFactor"), (uintptr_t)alDopplerFactor);
  hook_addr(so_symbol(&s4ep2_mod, "alDopplerVelocity"), (uintptr_t)alDopplerVelocity);
  hook_addr(so_symbol(&s4ep2_mod, "alEffectf"), (uintptr_t)alEffectf);
  hook_addr(so_symbol(&s4ep2_mod, "alEffectfv"), (uintptr_t)alEffectfv);
  hook_addr(so_symbol(&s4ep2_mod, "alEffecti"), (uintptr_t)alEffecti);
  hook_addr(so_symbol(&s4ep2_mod, "alEffectiv"), (uintptr_t)alEffectiv);
  hook_addr(so_symbol(&s4ep2_mod, "alEnable"), (uintptr_t)alEnable);
  hook_addr(so_symbol(&s4ep2_mod, "alFilterf"), (uintptr_t)alFilterf);
  hook_addr(so_symbol(&s4ep2_mod, "alFilterfv"), (uintptr_t)alFilterfv);
  hook_addr(so_symbol(&s4ep2_mod, "alFilteri"), (uintptr_t)alFilteri);
  hook_addr(so_symbol(&s4ep2_mod, "alFilteriv"), (uintptr_t)alFilteriv);
  hook_addr(so_symbol(&s4ep2_mod, "alGenBuffers"), (uintptr_t)alGenBuffers);
  hook_addr(so_symbol(&s4ep2_mod, "alGenEffects"), (uintptr_t)alGenEffects);
  hook_addr(so_symbol(&s4ep2_mod, "alGenFilters"), (uintptr_t)alGenFilters);
  hook_addr(so_symbol(&s4ep2_mod, "alGenSources"), (uintptr_t)alGenSources);
  hook_addr(so_symbol(&s4ep2_mod, "alGetAuxiliaryEffectSlotf"), (uintptr_t)alGetAuxiliaryEffectSlotf);
  hook_addr(so_symbol(&s4ep2_mod, "alGetAuxiliaryEffectSlotfv"), (uintptr_t)alGetAuxiliaryEffectSlotfv);
  hook_addr(so_symbol(&s4ep2_mod, "alGetAuxiliaryEffectSloti"), (uintptr_t)alGetAuxiliaryEffectSloti);
  hook_addr(so_symbol(&s4ep2_mod, "alGetAuxiliaryEffectSlotiv"), (uintptr_t)alGetAuxiliaryEffectSlotiv);
  hook_addr(so_symbol(&s4ep2_mod, "alGetBoolean"), (uintptr_t)alGetBoolean);
  hook_addr(so_symbol(&s4ep2_mod, "alGetBooleanv"), (uintptr_t)alGetBooleanv);
  hook_addr(so_symbol(&s4ep2_mod, "alGetBuffer3f"), (uintptr_t)alGetBuffer3f);
  hook_addr(so_symbol(&s4ep2_mod, "alGetBuffer3i"), (uintptr_t)alGetBuffer3i);
  hook_addr(so_symbol(&s4ep2_mod, "alGetBufferSamplesSOFT"), (uintptr_t)alGetBufferSamplesSOFT);
  hook_addr(so_symbol(&s4ep2_mod, "alGetBufferf"), (uintptr_t)alGetBufferf);
  hook_addr(so_symbol(&s4ep2_mod, "alGetBufferfv"), (uintptr_t)alGetBufferfv);
  hook_addr(so_symbol(&s4ep2_mod, "alGetBufferi"), (uintptr_t)alGetBufferi);
  hook_addr(so_symbol(&s4ep2_mod, "alGetBufferiv"), (uintptr_t)alGetBufferiv);
  hook_addr(so_symbol(&s4ep2_mod, "alGetDouble"), (uintptr_t)alGetDouble);
  hook_addr(so_symbol(&s4ep2_mod, "alGetDoublev"), (uintptr_t)alGetDoublev);
  hook_addr(so_symbol(&s4ep2_mod, "alGetEffectf"), (uintptr_t)alGetEffectf);
  hook_addr(so_symbol(&s4ep2_mod, "alGetEffectfv"), (uintptr_t)alGetEffectfv);
  hook_addr(so_symbol(&s4ep2_mod, "alGetEffecti"), (uintptr_t)alGetEffecti);
  hook_addr(so_symbol(&s4ep2_mod, "alGetEffectiv"), (uintptr_t)alGetEffectiv);
  hook_addr(so_symbol(&s4ep2_mod, "alGetEnumValue"), (uintptr_t)alGetEnumValue);
  hook_addr(so_symbol(&s4ep2_mod, "alGetError"), (uintptr_t)alGetError);
  hook_addr(so_symbol(&s4ep2_mod, "alGetFilterf"), (uintptr_t)alGetFilterf);
  hook_addr(so_symbol(&s4ep2_mod, "alGetFilterfv"), (uintptr_t)alGetFilterfv);
  hook_addr(so_symbol(&s4ep2_mod, "alGetFilteri"), (uintptr_t)alGetFilteri);
  hook_addr(so_symbol(&s4ep2_mod, "alGetFilteriv"), (uintptr_t)alGetFilteriv);
  hook_addr(so_symbol(&s4ep2_mod, "alGetFloat"), (uintptr_t)alGetFloat);
  hook_addr(so_symbol(&s4ep2_mod, "alGetFloatv"), (uintptr_t)alGetFloatv);
  hook_addr(so_symbol(&s4ep2_mod, "alGetInteger"), (uintptr_t)alGetInteger);
  hook_addr(so_symbol(&s4ep2_mod, "alGetIntegerv"), (uintptr_t)alGetIntegerv);
  hook_addr(so_symbol(&s4ep2_mod, "alGetListener3f"), (uintptr_t)alGetListener3f);
  hook_addr(so_symbol(&s4ep2_mod, "alGetListener3i"), (uintptr_t)alGetListener3i);
  hook_addr(so_symbol(&s4ep2_mod, "alGetListenerf"), (uintptr_t)alGetListenerf);
  hook_addr(so_symbol(&s4ep2_mod, "alGetListenerfv"), (uintptr_t)alGetListenerfv);
  hook_addr(so_symbol(&s4ep2_mod, "alGetListeneri"), (uintptr_t)alGetListeneri);
  hook_addr(so_symbol(&s4ep2_mod, "alGetListeneriv"), (uintptr_t)alGetListeneriv);
  hook_addr(so_symbol(&s4ep2_mod, "alGetProcAddress"), (uintptr_t)alGetProcAddress);
  hook_addr(so_symbol(&s4ep2_mod, "alGetSource3dSOFT"), (uintptr_t)alGetSource3dSOFT);
  hook_addr(so_symbol(&s4ep2_mod, "alGetSource3f"), (uintptr_t)alGetSource3f);
  hook_addr(so_symbol(&s4ep2_mod, "alGetSource3i"), (uintptr_t)alGetSource3i);
  hook_addr(so_symbol(&s4ep2_mod, "alGetSource3i64SOFT"), (uintptr_t)alGetSource3i64SOFT);
  hook_addr(so_symbol(&s4ep2_mod, "alGetSourcedSOFT"), (uintptr_t)alGetSourcedSOFT);
  hook_addr(so_symbol(&s4ep2_mod, "alGetSourcedvSOFT"), (uintptr_t)alGetSourcedvSOFT);
  hook_addr(so_symbol(&s4ep2_mod, "alGetSourcef"), (uintptr_t)alGetSourcef);
  hook_addr(so_symbol(&s4ep2_mod, "alGetSourcefv"), (uintptr_t)alGetSourcefv);
  hook_addr(so_symbol(&s4ep2_mod, "alGetSourcei"), (uintptr_t)alGetSourcei);
  hook_addr(so_symbol(&s4ep2_mod, "alGetSourcei64SOFT"), (uintptr_t)alGetSourcei64SOFT);
  hook_addr(so_symbol(&s4ep2_mod, "alGetSourcei64vSOFT"), (uintptr_t)alGetSourcei64vSOFT);
  hook_addr(so_symbol(&s4ep2_mod, "alGetSourceiv"), (uintptr_t)alGetSourceiv);
  hook_addr(so_symbol(&s4ep2_mod, "alGetString"), (uintptr_t)alGetString);
  hook_addr(so_symbol(&s4ep2_mod, "alIsAuxiliaryEffectSlot"), (uintptr_t)alIsAuxiliaryEffectSlot);
  hook_addr(so_symbol(&s4ep2_mod, "alIsBuffer"), (uintptr_t)alIsBuffer);
  hook_addr(so_symbol(&s4ep2_mod, "alIsBufferFormatSupportedSOFT"), (uintptr_t)alIsBufferFormatSupportedSOFT);
  hook_addr(so_symbol(&s4ep2_mod, "alIsEffect"), (uintptr_t)alIsEffect);
  hook_addr(so_symbol(&s4ep2_mod, "alIsEnabled"), (uintptr_t)alIsEnabled);
  hook_addr(so_symbol(&s4ep2_mod, "alIsExtensionPresent"), (uintptr_t)alIsExtensionPresent);
  hook_addr(so_symbol(&s4ep2_mod, "alIsFilter"), (uintptr_t)alIsFilter);
  hook_addr(so_symbol(&s4ep2_mod, "alIsSource"), (uintptr_t)alIsSource);
  hook_addr(so_symbol(&s4ep2_mod, "alListener3f"), (uintptr_t)alListener3f);
  hook_addr(so_symbol(&s4ep2_mod, "alListener3i"), (uintptr_t)alListener3i);
  hook_addr(so_symbol(&s4ep2_mod, "alListenerf"), (uintptr_t)alListenerf);
  hook_addr(so_symbol(&s4ep2_mod, "alListenerfv"), (uintptr_t)alListenerfv);
  hook_addr(so_symbol(&s4ep2_mod, "alListeneri"), (uintptr_t)alListeneri);
  hook_addr(so_symbol(&s4ep2_mod, "alListeneriv"), (uintptr_t)alListeneriv);
  hook_addr(so_symbol(&s4ep2_mod, "alProcessUpdatesSOFT"), (uintptr_t)alProcessUpdatesSOFT);
  hook_addr(so_symbol(&s4ep2_mod, "alSetConfigMOB"), (uintptr_t)ret0);
  hook_addr(so_symbol(&s4ep2_mod, "alSource3dSOFT"), (uintptr_t)alSource3dSOFT);
  hook_addr(so_symbol(&s4ep2_mod, "alSource3f"), (uintptr_t)alSource3f);
  hook_addr(so_symbol(&s4ep2_mod, "alSource3i"), (uintptr_t)alSource3i);
  hook_addr(so_symbol(&s4ep2_mod, "alSource3i64SOFT"), (uintptr_t)alSource3i64SOFT);
  hook_addr(so_symbol(&s4ep2_mod, "alSourcePause"), (uintptr_t)alSourcePause);
  hook_addr(so_symbol(&s4ep2_mod, "alSourcePausev"), (uintptr_t)alSourcePausev);
  hook_addr(so_symbol(&s4ep2_mod, "alSourcePlay"), (uintptr_t)alSourcePlay);
  hook_addr(so_symbol(&s4ep2_mod, "alSourcePlayv"), (uintptr_t)alSourcePlayv);
  hook_addr(so_symbol(&s4ep2_mod, "alSourceQueueBuffers"), (uintptr_t)alSourceQueueBuffers);
  hook_addr(so_symbol(&s4ep2_mod, "alSourceRewind"), (uintptr_t)alSourceRewind);
  hook_addr(so_symbol(&s4ep2_mod, "alSourceRewindv"), (uintptr_t)alSourceRewindv);
  hook_addr(so_symbol(&s4ep2_mod, "alSourceStop"), (uintptr_t)alSourceStop);
  hook_addr(so_symbol(&s4ep2_mod, "alSourceStopv"), (uintptr_t)alSourceStopv);
  hook_addr(so_symbol(&s4ep2_mod, "alSourceUnqueueBuffers"), (uintptr_t)alSourceUnqueueBuffers);
  hook_addr(so_symbol(&s4ep2_mod, "alSourcedSOFT"), (uintptr_t)alSourcedSOFT);
  hook_addr(so_symbol(&s4ep2_mod, "alSourcedvSOFT"), (uintptr_t)alSourcedvSOFT);
  hook_addr(so_symbol(&s4ep2_mod, "alSourcef"), (uintptr_t)alSourcef);
  hook_addr(so_symbol(&s4ep2_mod, "alSourcefv"), (uintptr_t)alSourcefv);
  hook_addr(so_symbol(&s4ep2_mod, "alSourcei"), (uintptr_t)alSourcei);
  hook_addr(so_symbol(&s4ep2_mod, "alSourcei64SOFT"), (uintptr_t)alSourcei64SOFT);
  hook_addr(so_symbol(&s4ep2_mod, "alSourcei64vSOFT"), (uintptr_t)alSourcei64vSOFT);
  hook_addr(so_symbol(&s4ep2_mod, "alSourceiv"), (uintptr_t)alSourceiv);
  hook_addr(so_symbol(&s4ep2_mod, "alSpeedOfSound"), (uintptr_t)alSpeedOfSound);
  hook_addr(so_symbol(&s4ep2_mod, "alcCaptureCloseDevice"), (uintptr_t)alcCaptureCloseDevice);
  hook_addr(so_symbol(&s4ep2_mod, "alcCaptureOpenDevice"), (uintptr_t)alcCaptureOpenDevice);
  hook_addr(so_symbol(&s4ep2_mod, "alcCaptureSamples"), (uintptr_t)alcCaptureSamples);
  hook_addr(so_symbol(&s4ep2_mod, "alcCaptureStart"), (uintptr_t)alcCaptureStart);
  hook_addr(so_symbol(&s4ep2_mod, "alcCaptureStop"), (uintptr_t)alcCaptureStop);
  hook_addr(so_symbol(&s4ep2_mod, "alcCloseDevice"), (uintptr_t)alcCloseDevice);
  hook_addr(so_symbol(&s4ep2_mod, "alcCreateContext"), (uintptr_t)alcCreateContextHook);
  hook_addr(so_symbol(&s4ep2_mod, "alcDestroyContext"), (uintptr_t)alcDestroyContext);
  hook_addr(so_symbol(&s4ep2_mod, "alcDeviceEnableHrtfMOB"), (uintptr_t)ret0);
  hook_addr(so_symbol(&s4ep2_mod, "alcGetContextsDevice"), (uintptr_t)alcGetContextsDevice);
  hook_addr(so_symbol(&s4ep2_mod, "alcGetCurrentContext"), (uintptr_t)alcGetCurrentContext);
  hook_addr(so_symbol(&s4ep2_mod, "alcGetEnumValue"), (uintptr_t)alcGetEnumValue);
  hook_addr(so_symbol(&s4ep2_mod, "alcGetError"), (uintptr_t)alcGetError);
  hook_addr(so_symbol(&s4ep2_mod, "alcGetIntegerv"), (uintptr_t)alcGetIntegerv);
  hook_addr(so_symbol(&s4ep2_mod, "alcGetProcAddress"), (uintptr_t)alcGetProcAddress);
  hook_addr(so_symbol(&s4ep2_mod, "alcGetString"), (uintptr_t)alcGetString);
  hook_addr(so_symbol(&s4ep2_mod, "alcGetThreadContext"), (uintptr_t)alcGetThreadContext);
  hook_addr(so_symbol(&s4ep2_mod, "alcIsExtensionPresent"), (uintptr_t)alcIsExtensionPresent);
  hook_addr(so_symbol(&s4ep2_mod, "alcIsRenderFormatSupportedSOFT"), (uintptr_t)alcIsRenderFormatSupportedSOFT);
  hook_addr(so_symbol(&s4ep2_mod, "alcLoopbackOpenDeviceSOFT"), (uintptr_t)alcLoopbackOpenDeviceSOFT);
  hook_addr(so_symbol(&s4ep2_mod, "alcMakeContextCurrent"), (uintptr_t)alcMakeContextCurrent);
  hook_addr(so_symbol(&s4ep2_mod, "alcOpenDevice"), (uintptr_t)alcOpenDevice);
  hook_addr(so_symbol(&s4ep2_mod, "alcProcessContext"), (uintptr_t)alcProcessContext);
  hook_addr(so_symbol(&s4ep2_mod, "alcRenderSamplesSOFT"), (uintptr_t)alcRenderSamplesSOFT);
  hook_addr(so_symbol(&s4ep2_mod, "alcSetThreadContext"), (uintptr_t)alcSetThreadContext);
  hook_addr(so_symbol(&s4ep2_mod, "alcSuspendContext"), (uintptr_t)alcSuspendContext);
}
