#ifndef BUBBLY_MOUSE_H
#define BUBBLY_MOUSE_H
namespace Bubbly {
    class Mouse {
    public:
        enum Button {
            RIGHT, LEFT, MIDDLE
        };

        static glm::vec2 getPosition();

        static bool isButtonPressed(Button);
    };
}

#endif