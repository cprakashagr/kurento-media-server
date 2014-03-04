/* Autogenerated with Kurento Idl */

#ifndef __DISPATCHER_MIXER_HPP__
#define __DISPATCHER_MIXER_HPP__

#include <jsoncpp/json/json.h>
#include <JsonRpcException.hpp>
#include <ObjectRegistrar.hpp>
#include <memory>
#include <vector>
#include "MediaMixer.hpp"

namespace kurento {

class MediaPipeline;
class MixerPort;

class DispatcherMixer : public virtual MediaMixer {

public:

  DispatcherMixer () {};
  virtual ~DispatcherMixer () {};

  virtual void setSource (std::shared_ptr<MixerPort> source) {throw "Not implemented";};
  virtual void removeSource () {throw "Not implemented";};

  virtual std::string connect(const std::string &eventType, std::shared_ptr<EventHandler> handler);

  class Factory : public virtual kurento::Factory
  {
  public:
    Factory () {};

    virtual std::shared_ptr<MediaObject> createObject (const Json::Value
        &params);

    virtual std::string getName () {
      return "DispatcherMixer";
    };

  private:

    std::shared_ptr<MediaObject> createObject (std::shared_ptr<MediaPipeline> mediaPipeline, int garbagePeriod);

    class StaticConstructor
    {
    public:
      StaticConstructor();
    };

    static StaticConstructor staticConstructor;

  };

  class Invoker : public virtual MediaMixer::Invoker
  {
  public:
    Invoker() {};
    virtual void invoke (std::shared_ptr<MediaObject> obj,
        const std::string &methodName, const Json::Value &params,
        Json::Value &response);
  };

  virtual MediaObject::Invoker &getInvoker() {
    return invoker;
  }

  private:
    Invoker invoker;

};

} /* kurento */

#endif /*  __DISPATCHER_MIXER_HPP__ */
