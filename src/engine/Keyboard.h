#ifndef BUBBLY_KEYBOARD_H
#define BUBBLY_KEYBOARD_H

namespace Bubbly {
    class Keyboard {
    public:
        enum Key {
            SPACE
        };

        static bool isKeyPressed(Key);
    };

}
#endif
