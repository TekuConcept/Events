/**
 * Created by TekuConcept on July 23, 2017
 */

#ifndef FUNCTION_COMMAND_H
#define FUNCTION_COMMAND_H

#include <memory>
#include "EventCommand.h"

template <class Args>
class StaticCommand : public EventCommand<Args> {
public:
    typedef void (* Action)(Object& sender, Args e);
    
    StaticCommand(Action a);
    
    virtual void invoke(Object& sender, Args e) {
        (*_action_)(sender, e);
    }
    
private:
    Action _action_;
};

template <class Args>
StaticCommand<Args>::StaticCommand(Action a) : _action_(a) {};

#define StaticCommandPtr(e, f) std::make_shared<StaticCommand<e>>(&f)

#endif