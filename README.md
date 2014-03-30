dtplayer for Linux
========

dtplayer is an open-sourced project, published under GPLv3 for individual/personal users .

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

Introduction
========

dtplayer is based on C , aimed to provide multimedia playing service base on ffmpeg2.0.

At present, dtplayer have provided examples on stream-demuxer-decoder-render modules. User can easily understand how to add new element.

if cmake does not detect a ffmpeg install but detect a faac install,
then you will get a aac player.

Compile
========

1 install sdl2.0

2 install ffmpeg-devel (libav-dev in deb)

3 mkdir -pv build && cd build && cmake .. && make

Test
========

./dtm_player url

Bug Report
=========
peter_future@outlook.com

Blog
=========
http://blog.csdn.net/u011350110/article/details/10718661

