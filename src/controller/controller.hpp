#include <zephyr/kernel.h>
#include "sm/state_machine.hpp"

namespace zephyrtest::controller {
    class Controller {
        public:
            explicit Controller(sm::StateMachine& sm);
            ~Controller();
            void run();
            static void update(void* instance, void *, void *);
        private:
            struct k_thread sm_thread {};
            sm::StateMachine& state_machine;
    };
}