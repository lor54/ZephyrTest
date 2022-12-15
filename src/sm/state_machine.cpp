#include "state_machine.hpp"
namespace zephyrtest::sm {
    static struct s_object {
        struct smf_ctx ctx;
        StateMachine* sm;
    } s_obj;
    const struct smf_state states[3] = {
        [INITIALIZE] = SMF_CREATE_STATE(NULL, StateMachine::initialize, NULL),
        [WAIT] = SMF_CREATE_STATE(NULL, StateMachine::wait, NULL),
        [DONE] = SMF_CREATE_STATE(NULL, StateMachine::done, NULL),
    };

    void StateMachine::initialize(void *o) {
        s_object* obj = (s_object*) o;
        obj->sm->setActualState(INITIALIZE);

        printk("Ciao 1!\n");
        smf_set_state(SMF_CTX(&s_obj), &states[WAIT]);
    }

    void StateMachine::wait(void *o) {
        s_object* obj = (s_object*) o;
        obj->sm->setActualState(WAIT);

        printk("Ciao 2!\n");
        smf_set_state(SMF_CTX(&s_obj), &states[DONE]);
    }

    void StateMachine::done(void *o) {
        s_object* obj = (s_object*) o;
        obj->sm->setActualState(DONE);

        printk("Ciao 3!\n");
        smf_set_terminate(SMF_CTX(&s_obj), 1);
    }

    StateMachine::StateMachine() {
        actualState = INITIALIZE;
    }

    StateMachine::~StateMachine() = default;

    int32_t StateMachine::execute() {
        s_obj.sm = this;
        smf_set_initial(SMF_CTX(&s_obj), &states[INITIALIZE]);

        int32_t ret;
        while(1) {
            ret = smf_run_state(SMF_CTX(&s_obj));
            if(ret) break;

            k_msleep(1000);
        }
        return ret;
    }

    state StateMachine::getActualState() {
        return actualState;
    }

    void StateMachine::setActualState(state actual) {
        actualState = actual;
    }
}