# rubberheik

Clone the repository and submodules

    git clone [url]
    git submodule update --init --recursive

Make example for this keyboard (after setting up your build environment):

    make disobey2018:default

`default` refers to the keymap, that can be found from the `keymap` folder

Or if you are using `qmk` cli wrapper

    QMK_HOME='~/' qmk compile --keyboard rubberheik --keymap default

Flashing example for this keyboard:

    make disobey2018:default:dfu-util

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
