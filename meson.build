###############################################################################
# NAME:             meson.build
#
# AUTHOR:           Ethan D. Twardy <ethan.twardy@gmail.com>
#
# DESCRIPTION:      Build script.
#
# CREATED:          01/30/2022
#
# LAST EDITED:      01/30/2022
#
# Copyright 2022, Ethan D. Twardy
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
###

project('rom-tortuga', 'c', version: '0.1.0')

gnome = import('gnome')
resources = gnome.compile_resources(
  'resources', 'rom-runner/rom-runner.gresource.xml',
  source_dir: 'rom-runner'
)

libgtk = dependency('gtk4')

executable(
  'rom-runner',
  sources: [
    'rom-runner/main.c',
    'rom-runner/game-list.c',
    'rom-runner/rom-runner-app.c',
    'rom-runner/rom-runner-app-window.c',
    resources,
  ],
  c_args: ['-frecord-gcc-switches'],
  install: true,
  dependencies: [libgtk],
)

###############################################################################
