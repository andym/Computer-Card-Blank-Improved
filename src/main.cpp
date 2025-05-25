#include <cmath>

#include "ComputerCard.h"
#include "ComputerCardExtensions.h"

//// An improved "blank card"
// On startup, we pulse the bottom two LEDs 3 times
// Then we play a nice sine wave at 440Hz out of both audio outputs
// If you hold the toggle switch down for 2 seconds, it will enter USB
// bootloader mode And you can flash new firmware via USB, and it will no longer
// be blank!
//
// Original source: https://github.com/andym/Computer-Card-Blank-Improved
//
// This project builds with the PICO SDK and uses the ComputerCard library

class MyCustomCard : public CardExtensions::ExtendedCard {
 private:
  // Create a custom pattern using the PatternBuilder
  static const CardExtensions::StartupPatterns::Pattern MyCustomPattern;

 public:
  MyCustomCard() {
    // Card automatically handles startup pattern and boot sequence
  }

 protected:
  const CardExtensions::StartupPatterns::Pattern& GetStartupPattern() override {
    return CardExtensions::StartupPatterns::BlankCard;
  }

  // Called once when startup pattern completes
  void OnStartupComplete() override {
    // Optional: do any initialization after the pattern finishes
  }

  // Your main card functionality - only called after startup
  void ProcessMainSample() override {
    // output sine wave for audio
    static float phase = 0.0f;
    int32_t out = int32_t(2000 * sinf(phase));
    AudioOut1(out);
    AudioOut2(out);
    phase += (float)M_TWOPI * 440.0f / 48000.0f;
    if (phase > (float)M_TWOPI) phase -= (float)M_TWOPI;

    // Your LED effects go here
    // LEDs are now available for your main application
    // (startup pattern has completed)
  }
};

int main() {
  MyCustomCard card;
  card.RunWithBootSupport();  // Handles USB boot if switch held
}