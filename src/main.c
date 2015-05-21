#include <pebble.h>
#include "main.h"
  
static uint32_t const segments[] = { 9600, 400, 9600, 400, 9600, 400, 9600, 400, 9600, 400, 9600, 400 };  

static void init(void) {

  wakeup_service_subscribe(NULL);
  wakeup_schedule(time(NULL) + 60, 0, false);
  
  vibes_cancel();
  
  VibePattern pat = {
    .durations = segments,
    .num_segments = ARRAY_LENGTH(segments),
  };
  vibes_enqueue_custom_pattern(pat);
  
}


int main(void) {
  init();
  app_event_loop();
}