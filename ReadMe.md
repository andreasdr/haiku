Haiku
=======================
**[Homepage](https://www.haiku-os.org/)
| [Mailing Lists](https://www.haiku-os.org/community/ml)
| [IRC Channels](https://www.haiku-os.org/community/irc)
| [Issue Tracker](https://dev.haiku-os.org/)
| [API docs](https://api.haiku-os.org)**

Haiku is an open-source operating system that specifically targets personal
computing. Inspired by the BeOS, Haiku is fast, simple to use, easy to learn
and yet very powerful.

WHAAATTTTZ DIS FORK EXACTLY???
--------------------------------

NOTE: This is my DRM port attempt based on OpenBSDs 6.8 DRM kernel modules.
I choosed OpenBSD because they have ported DRM in a way I think I can maybe somehow cope with.
Porting directly from Linux would not work for me as it would cost much more time and knowledge.

OpenBSD people did a great job by adding a kind of Linux layer that can be ported to Haiku step by step.
Unfortunatly some porting is also required in the DRM modules itself.

I know I am crazy, but lets check this.

It does compile already, but does not yet do anything useful, also it does not link of course :D
I ll add instructions soon how to build the radeondrm.

First DRM module I want to try to port is RADEONDRM as its the smallest driver available.

What I have seen so far that needs porting is
- PCI related API and logics
- DMA transfers and such
- I2C access
- VM related logics
- Task injection / scheduling
- ...

What we else need
- IOCTL interface to user land
- Device file interface
- Some interaction with Radeon accelerant
- LIBDRM to be ported and tell MESA to use it
- Obviously the DRM module needs also to get loaded on boot

Sorry If anythings wrong here, I am just a small programmer guy. :D

How to build, starting from your home folder. I used a fresh Haiku installation also:
```bash
mkdir Development
cd Development
mkdir Haiku
cd Haiku
git clone https://review.haiku-os.org/buildtools
git clone https://github.com/andreasdr/haiku.git
cd haiku
./configure --cross-tools-source ../buildtools --build-cross-tools x86_64
jam
mkdir generated/objects/haiku/x86_64/release/add-ons/kernel/drivers/drm/radeondrm/drm
mkdir generated/objects/haiku/x86_64/release/add-ons/kernel/drivers/drm/radeondrm/drm/radeon
cd src/add-ons/kernel/drivers/drm/radeondrm
jam
```

This can be improved of course, but its the way I compile radeondrm currently.

I can list here later files that needs porting love if someone wants to join. I also hang out on IRC in #Haiku channel with the nick andreasdr.

Goals
------------
 * Sensible defaults with minimal configuration required.
 * Clean, clear, concise code.
 * Unified desktop environment.

Trying Haiku
---------------
Haiku provides pre-built [nightly images](http://download.haiku-os.org/) and
[release images](https://www.haiku-os.org/get-haiku). Haiku is compatible
with a large variety of hardware, but in case you don't want to "take the
plunge" and install Haiku on bare metal, you can install it on a virtual
machine (VM) instead. If you've never used a VM before, you can follow one of
the ["Emulating Haiku"](https://www.haiku-os.org/guides/virtualizing/) guides.

Compiling Haiku
---------------
See `ReadMe.Compiling`.

Contributing
-------------------
Haiku is a meritocratic open source project with a large variety of tasks. Even
if you can't write code, *you can still help*! Haiku needs designers,
(technical) writers, translators, testers... Get involved and help out!

### Contributing code
If you're submitting a patch to us, please make sure you're following the
[patch submitting guidelines](https://dev.haiku-os.org/wiki/CodingGuidelines/SubmittingPatches).

If you're having trouble finding something in the source tree, you can use
one of our web-based source code browsers:

 * https://xref.landonf.org/ (OpenGrok, provided by Landon Fuller)
 * https://git.haiku-os.org/ (git, provided by Haiku, Inc.)

### Contributing documentation
The main piece of documentation that still needs work are the API docs (found
in the tree at `docs/user`). Just find an undocumented class, write
documentation for it, and [submit a patch](https://dev.haiku-os.org/wiki/CodingGuidelines/SubmittingPatches).

### Contributing translations
See [wiki:i18n](https://dev.haiku-os.org/wiki/i18n).

### Contributing software ports
See [HaikuPorts](https://github.com/haikuports/haikuports/).

### Contributing to our infrastructure
See [Infrastructure](https://github.com/haiku/infrastructure/).
