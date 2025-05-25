# Improved blank card for the music thing modular workshop computer

## TLDR

Burn this to your blank cards. It identifies itself by blinking the two LEDs in the bottom row 3 times when it starts up and if you hold the toggle switch down for a few seconds then computer reboots into the mode where it's ready to have a new card written to it.

## But why?

I couldn't tell the difference between the chasing LEDs of a blank card and a MIDI card with no usb plugged in. Also it makes sense that a blank card should be easy to write to.

## This is too fancy for a blank card

Well, it's actually a re-usable library and a project template.

Copy the whole project off and add your card functionality. You can easily set your own startup animation and you get an easy method of uploading the card as you develop it. When you actually have a use for the toggle, you can just stop using that feature and go back to the bootsel dance.

You can also just copy off the ComputerCardExtensions.h file to your project and use it. You'll need ComputerCard.h as well from [here](https://github.com/TomWhitwell/Workshop_Computer/tree/main/Demonstrations%2BHelloWorlds/PicoSDK/ComputerCard)

## Details Details

The hold-the-toggle-down idea came from the [sample upload project](https://github.com/TomWhitwell/Workshop_Computer/tree/main/Demonstrations%2BHelloWorlds/PicoSDK/ComputerCard/examples/sample_upload)

The little startup animiation has an entirely overwrought concept behind it. The goal was that it should be possible to know which card you've got plugged in without having to take it out and turn it over to look at. Each card can have it's own little unique animation when it starts up. Each animation has 3 "notes" loosely based on the Kodály concept. The most fundamental boring card - the blank card  - starts up with "Do-Do-Do". A sequencer card could be "Do-Re-Mi", etc. Each note is a unique pattern on the 6 LEDs. The library contains some common ideas but you can also use it to build your own 3 note sequences.

I've been building this using the pico sdk. It may work with arduino, but I haven't tried.
