# Arduino Magnet Wheel Interface for Video Game Character Movement

This Arduino sketch allows users to emulate keyboard presses to control a video game character's movement based on the rotation of a magnet attached to a wheel. The wheel is designed to run on a treadmill, and as a person walks forward, the character in the game will move forward accordingly.

## Components Used

- **Arduino Board**: Any compatible Arduino board can be used.
- **Magnet Wheel**: A wheel with a magnet attached to it, running on a treadmill.
- **Infrared Sensor**: Used to detect the passage of the magnet.
- **Computer**: Running the video game, connected to the Arduino board.

## Code Description

### Libraries Used

- `Keyboard.h`: Allows the Arduino to emulate keyboard presses.

### Variables

- **`ctrlKey`**: Defines the control key to be used for emulating key presses (e.g., 'Command' key on macOS).
- **`ir_pin`**: Pin connected to the infrared sensor.
- **`counter`**: Counts the number of passes of the magnet.
- **`state`**: Tracks the current state of the infrared sensor.
- **`spokePass`**: Indicates whether a spoke of the wheel has passed.
- **`blipsPerRev`**: Number of blips (magnet passes) per revolution of the wheel.
- **`timeOne`, `timeTwo`**: Variables to measure the time between magnet passes.

### Setup Function

- **`setup()`**: Initializes serial communication, sets the IR pin as input, and starts the keyboard interface.

### Loop Function

- **`loop()`**: 
  - Reads the state of the IR sensor.
  - When a magnet passes the sensor:
    - Increments the counter.
    - Determines if the time between passes indicates walking speed.
    - Emulates keyboard presses accordingly (forward movement).
  - Resets `spokePass` when the magnet moves away from the sensor.

## Operation

1. Connect the Arduino to the computer running the video game.
2. Attach the magnet wheel to the treadmill and position the infrared sensor appropriately.
3. Run the Arduino sketch on the board.
4. Start walking on the treadmill, and the character in the game will move forward based on the rotations of the wheel.

## Notes

- Adjust the `blipsPerRev` value according to the number of magnet passes per wheel revolution.
- Customize the key presses (`'w'` and `'u'`) to match the controls of the video game.
- Ensure the infrared sensor is positioned accurately to detect magnet passes reliably.
- Experiment with the delay values to fine-tune character movement responsiveness.
