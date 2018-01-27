#ifndef BUBBLYENGINE_KEYBOARD_H
#define BUBBLYENGINE_KEYBOARD_H

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
