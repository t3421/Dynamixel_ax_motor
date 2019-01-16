# Dynamixel_ax_motor
dynamixel motor inferface with a arduino board

note:
  motor1 has the id of 10.
  motor2 has the id of 20.
  the buadrate is very high, might need to lower it.

In order to use this you need to add the libries for the the dynamixel motor
  "ardyno by Adrien Descamps Version 0.9.0"
  to add the libries simply click Tools then Library Manager, search from the above and install.

When pushing to the Arduino board the TX ad RX wires need to be removed as it will interfere with the upload.

Hook the wires in the order of ground to black with white stripe, vdd is center, other is data.

The recomended power is around 9.6V but the motors can work well with up to 12v but starts to drop off lower then 9V or so.
