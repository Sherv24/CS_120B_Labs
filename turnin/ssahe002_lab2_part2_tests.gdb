# Test file for "Lab2_introToAVR"


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n

# Example test:
#test "PINA: 0x00, PINB: 0x00 => PORTC: 0"
# Set inputs
#setPINA 0x00
#setPINB 0x00
# Continue for several ticks
#continue 2
# Set expect values
#expectPORTC 0
# Check pass/fail
#checkResult

# Add tests below
#test “PINA[1:0]: 00, PORTB0: 0”
#setPINA 0x00
#continue 2
#expectPORTB 0x00
#checkResult

#test “PINA[1:0]: 01, PORTB0: 1”
#setPINA 0x01
#continue 2
#expectPORTB 0x01
#checkResult

test "0 parking spots in use: PORTC: 0x04"
setPINA 0x00
continue 5
expectPORTC 0x04
checkResult

test "1 parking spot in use: PORTC: 0x03"
setPINA 0x04
continue 5
expectPORTC 0x03
checkResult

test "2 parking spots in use: PORTC: 0x02"
setPINA 0x06
continue 5
expectPORTC 0x02
checkResult

test "3 parking spots in use: PORTC: 0x01"
setPINA 0x07
continue 5
expectPORTC 0x01
checkResult

test "4 parking spots in use: PORTC: 0x80"
setPINA 0x0F
continue 5
expectPORTC 0x00
checkResult

# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
