# The test keymap for willow/pecoe

This test firmware is only for left-sided rotary encoder (Side-A is surface)
for now.

It starts RGB light with test pattern.  Test pattern means all LEDs will light
and change those color: red, green, blue at constant interval.

Test keymap is very simple to test keys.  No layersk, no tappings or so.  You
can test all keys (and a rotary encoder also) with
<https://config.qmk.fm/#/test/> easily.

## Rotary Encoder

Rotation of a rotary encoder is parsed as `Page Up` (counter clockwise) or
`Page Down` (clockwise) keys as normal.

Pressing switch of rotary encoder changes hidden-internal mode to parse
rotation of rotary encoder.  When changed the mode, rotation is parsed as
`Home` (counter clockwise) or `End` (clockwise).  Then press a switch again to
return to the original parsing mode.

Parsing mode is indicated with RGB LEDs.  For normal mode, RGB light will be
enabled with test pattern.  For alternative mode, RGB light will be disabeld,
all LEDs are turned off.
