#pragma once
#ifndef DSY_FLANGER_H
#define DSY_FLANGER_H
#ifdef __cplusplus

#include <stdint.h>
#include "Utility/delayline.h"

/** @file flanger.h */

namespace apalis
{

class Flanger
{
  public:
    /** Initialize the modules
        \param sample_rate Audio engine sample rate.
    */
    void Init(float sample_rate);

    /** Get the next sample
        \param in Sample to process
    */
    float Process(float in);

    /** How much of the signal to feedback into the delay line.
        \param feedback Works 0-1.
    */
    void SetFeedback(float feedback);

    /** How much to modulate the delay by.
        \param depth Works 0-1.
    */
    void SetLfoDepth(float depth);

    /** Set lfo frequency.
        \param freq Frequency in Hz
    */
    void SetLfoFreq(float freq);

    /** Set the internal delay rate. 
        \param delay Tuned for 0-1. Maps to .1 to 7 ms.
    */
    void SetDelay(float delay);

    /** Set the delay time in ms.
        \param ms Delay time in ms, .1 to 7 ms.
    */
    void SetDelayMs(float ms);

  private:
    float                    sample_rate_;

    float feedback_;

    float lfo_phase_;
    float lfo_freq_;
    float lfo_amp_;

    float delay_;

    DelayLine<float, kDelayLength> del_;

    float ProcessLfo();
};
#endif
#endif
