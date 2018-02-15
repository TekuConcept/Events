/**
 * Created by TekuConcept on July 23, 2017
 */

#ifndef STATIC_COMMAND_H
#define STATIC_COMMAND_H

#include <memory>
#include "EventCommand.h"

#include <functional>

template <class Args>
class StaticCommand : public EventCommand<Args> {
public:
    StaticCommand(std::function<void (Object&,Args)> a);
    
    virtual void invoke(Object& sender, Args e) {
        _action_(sender,e);
    }
    
private:
    std::function<void (Object&,Args)> _action_;
};

template <class Args>
StaticCommand<Args>::StaticCommand(std::function<void (Object&,Args)> a) :
    _action_(a) {};

#define StaticCommandPtr(e, f) std::make_shared<StaticCommand<e>>(&f)
#define LambdaCommandPtr(e, f) std::make_shared<StaticCommand<e>>(f)

#endif