// Copyright (c) 2014 Arista Networks, Inc.  All rights reserved.
// Arista Networks, Inc. Confidential and Proprietary.

#ifndef EXAMPLES_LIBEVENT_H
#define EXAMPLES_LIBEVENT_H

#include <eos/event_loop.h>

class libevent_loop : public eos::event_loop_handler {
 public:
   explicit libevent_loop(event_base * eb) : eb_(eb) {
   }

   virtual ~libevent_loop() {
   }

   void init();
   virtual void watch_readable(int fd, bool interested);
   virtual void watch_writable(int fd, bool interested);
   virtual void watch_exception(int fd, bool interested);
   virtual void timeout_time_is(struct timeval deadline);

 private:
   event_base * const eb_;
   eos::event_loop loop_;
};

#endif // EXAMPLES_LIBEVENT_H
