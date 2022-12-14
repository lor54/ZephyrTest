#include <zephyr/smf.h>
#include "common/common.hpp"
namespace zephyrtest::sm {
    class StateMachine {
        public:
            explicit StateMachine();
            ~StateMachine();

            int32_t execute();
            state getActualState();
            void setActualState(state actual);

            static void initialize(void *o);
            static void wait(void *o);
            static void done(void *o);

        private:
            state actualState;
    };
}