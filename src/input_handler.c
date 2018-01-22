/** input_handler
 *
 *      Handles our input.
 *      Use InputHandler_is_key_held, is_key_pressed, and is_key_released 
 *      to check for keyboard inputs
 *
 */

#include "input_handler.h"

#include<SDL2/SDL.h>
#include<stdbool.h>

// Whether we're pressing the key currently
bool InputHandler_key_accelerate = false;
bool InputHandler_key_turn_left = false;
bool InputHandler_key_shoot = false;

// Previous keys (so we can tell whether we just pressed a key)
bool InputHandler_key_accelerate_prev = false;
bool InputHandler_key_turn_left_prev = false;
bool InputHandler_key_shoot_prev = false;

/** InputHandler_press_key( key )
 *      Sets a key to true, so that we can say it's being held
 *
 */
void InputHandler_press_key(SDL_Keycode key) {
    switch (key) {
        case INPUT_KEY_ACCELERATE:
            InputHandler_key_accelerate = true;
            break;
        case INPUT_KEY_TURN_LEFT:
            InputHandler_key_turn_left = true;
            break;
        case INPUT_KEY_SHOOT:
            InputHandler_key_shoot = true;
            break;
    }
}

/** InputHandler_release_key( key )
 *      Sets a key to false, so that we can say it's NOT being held
 *
 */
void InputHandler_release_key(SDL_Keycode key) {
    switch (key) {
        case INPUT_KEY_ACCELERATE:
            InputHandler_key_accelerate = false;
            break;
        case INPUT_KEY_TURN_LEFT:
            InputHandler_key_turn_left = false;
            break;
        case INPUT_KEY_SHOOT:
            InputHandler_key_shoot = false;
            break;
    }
}

/** InputHandler_tick()
 *      Tick (update) for input. Called once per frame, at the END of every frame.
 *      Sets our previous inputs so that we can detect 
 *      what our previous inputs were.
 */
void InputHandler_tick() {
    InputHandler_key_accelerate_prev = InputHandler_key_accelerate;
    InputHandler_key_turn_left_prev = InputHandler_key_turn_left;
    InputHandler_key_shoot_prev = InputHandler_key_shoot;
}


bool InputHandler_is_key_held(SDL_Keycode key) {
    switch (key) {
        case INPUT_KEY_ACCELERATE:
            return InputHandler_key_accelerate;
        case INPUT_KEY_TURN_LEFT:
            return InputHandler_key_turn_left;
        case INPUT_KEY_SHOOT:
            return InputHandler_key_shoot;
        default:
            return false;
    }
}

bool InputHandler_is_key_pressed(SDL_Keycode key) {
    switch (key) {
        case INPUT_KEY_ACCELERATE:
            return InputHandler_key_accelerate && !InputHandler_key_accelerate_prev;
        case INPUT_KEY_TURN_LEFT:
            return InputHandler_key_turn_left && !InputHandler_key_turn_left;
        case INPUT_KEY_SHOOT:
            return InputHandler_key_shoot && !InputHandler_key_shoot;
        default:
            return false;
    }
}

bool InputHandler_is_key_released(SDL_Keycode key) {
    switch (key) {
        case INPUT_KEY_ACCELERATE:
            return !InputHandler_key_accelerate && InputHandler_key_accelerate_prev;
        case INPUT_KEY_TURN_LEFT:
            return !InputHandler_key_turn_left && InputHandler_key_turn_left;
        case INPUT_KEY_SHOOT:
            return !InputHandler_key_shoot && InputHandler_key_shoot;
        default:
            return false;
    }
}
