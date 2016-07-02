#include "timer.h"

Timer::Timer() {
  history = new Array<float>();
  current = clock();
  name = "Timer: ";
}

Timer::Timer(string param) {
  history = new Array<float>();
  current = clock();
  name = param;
}

Timer::~Timer() {
  while(history->getSize()) history->removeLast();
  delete history;
}

void Timer::clearHistory() {
  while(history->getSize()) history->removeLast();
  delete history;
}

void Timer::start() {
  current = clock();
}

float Timer::stop() {
  clock_t time = clock();
  float interval = (time - current) / CLOCKS_PER_SEC;
  history->add(interval);
  current = time;
  return interval;
}

void Timer::reset() {
  clock_t time = clock();
  current = time;
}

void Timer::lap() {
  clock_t time = clock();
  float interval = (time - current) / CLOCKS_PER_SEC;
  history->add(interval);
}

void Timer::push() {
  stop();
}

float Timer::peek() {
  return history->get(history->getSize()-1);
}

void Timer::printHistory() {
  for(int i=0;i<history->getSize();i++)
    cout << name << history->get(i) << endl;
}
