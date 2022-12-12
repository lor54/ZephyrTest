#include <zephyr/smf.h>

namespace zephyrtest::sm {
    class StateMachine {
        public:
            explicit StateMachine();
            ~StateMachine();
            void run();

            static void initialize(void *o);
            static void wait(void *o);
            static void done(void *o);
        private:
    };
}