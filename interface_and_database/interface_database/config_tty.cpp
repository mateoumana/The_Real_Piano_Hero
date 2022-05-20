/*https://blog.mbedded.ninja/programming/operating-systems/linux/linux-serial-ports-using-c-cpp/
  https://github.com/gbmhunter/CppLinuxSerial.
  Michael R. Sweet (1999). Serial Programming Guide for POSIX Operating Systems. Retrieved 2022-02-12, from https://www.cmrr.umn.edu/~strupp/serial.html. ??
  http://www.gnu.org/software/libc/manual/html_node/Mode-Functions.html ??
*/
#include "tty_lib2.h"

void config_tty (const char *tty_port, struct termios *tty, unsigned int baud, int *serial_port)
{
	
	*serial_port = open(tty_port, O_RDWR);

	// Check for errors
	if (*serial_port < 0) {
		printf("Error %i from open: %s\n", errno, strerror(errno));
	}
	
	
	// Create new termios struct, we call it 'tty' for convention
	// No need for "= {0}" at the end as we'll immediately write the existing
	// config to this struct
	//struct termios tty;//no needed here as is received in function argument 

	// Read in existing settings, and handle any error
	// NOTE: This is important! POSIX states that the struct passed to tcsetattr()
	// must have been initialized with a call to tcgetattr() overwise behaviour
	// is undefined
	if(tcgetattr(*serial_port, tty) != 0) {
		printf("Error %i from tcgetattr: %s\n", errno, strerror(errno));
	}

	tty->c_cflag &= ~PARENB; // Clear parity bit, disabling parity (most common)
	//tty->c_cflag |= PARENB;  // Set parity bit, enabling parity
	
	tty->c_cflag &= ~CSTOPB; // Clear stop field, only one stop bit used in communication (most common)
	//tty->c_cflag |= CSTOPB;  // Set stop field, two stop bits used in communication
	

	tty->c_cflag &= ~CSIZE; // Clear all the size bits, then use one of the statements below
	//tty->c_cflag |= CS5; // 5 bits 
	//tty->c_cflag |= CS6; // 6 bits
	//tty->c_cflag |= CS7; // 7 bits 
	tty->c_cflag |= CS8; // 8 bits (most common)

	
	tty->c_cflag &= ~CRTSCTS; // Disable RTS/CTS hardware flow control (most common)
	//tty->c_cflag |= CRTSCTS;  // Enable RTS/CTS hardware flow control

	tty->c_cflag |= CREAD | CLOCAL; // Turn on READ & ignore ctrl lines (CLOCAL = 1)

	//In canonical mode, input is processed when a new line character is received.
	tty->c_lflag &= ~ICANON; // non-canonical 
	
	//If this bit is set, sent characters will be echoed back.
	tty->c_lflag &= ~ECHO; // Disable echo
	tty->c_lflag &= ~ECHOE; // Disable erasure
	tty->c_lflag &= ~ECHONL; // Disable new-line echo

	tty->c_lflag &= ~ISIG; // Disable interpretation of INTR, QUIT and SUSP

	tty->c_iflag &= ~(IXON | IXOFF | IXANY); // Turn off s/w flow ctrl

	tty->c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL); // Disable any special handling of received bytes

	tty->c_oflag &= ~OPOST; // Prevent special interpretation of output bytes (e.g. newline chars)
	tty->c_oflag &= ~ONLCR; // Prevent conversion of newline to carriage return/line feed
	// tty->c_oflag &= ~OXTABS; // Prevent conversion of tabs to spaces (NOT PRESENT IN LINUX)
	// tty->c_oflag &= ~ONOEOT; // Prevent removal of C-d chars (0x004) in output (NOT PRESENT IN LINUX)
	
	
  /*VMIN = 0, VTIME = 0: No blocking, return immediately with what is available
	VMIN > 0, VTIME = 0: This will make read() always wait for bytes (exactly how many is determined by VMIN), so read() could block indefinitely.
	VMIN = 0, VTIME > 0: This is a blocking read of any number of chars with a maximum timeout (given by VTIME). read() will block until either any amount of data is available, or the timeout occurs. This happens to be my favourite mode (and the one I use the most).
	VMIN > 0, VTIME > 0: Block until either VMIN characters have been received, or VTIME after first character has elapsed. Note that the timeout for VTIME does not begin until the first character is received.
	type of VMIN and VTIME: cc_t (1B)*/
	tty->c_cc[VTIME] = 0; 
	tty->c_cc[VMIN] = 1; // wait one byte
	
	//B0,  B50,  B75,  B110,  B134,  B150,  B200, B300, B600, B1200, B1800, B2400, B4800, B9600, B19200, B38400, B57600, B115200, B230400, B460800
	// Set in/out baud rate to be 9600
	cfsetispeed(tty, baud);
	cfsetospeed(tty, baud);
	//cfsetspeed(tty, B9600); //set both input and output

	//cfsetispeed(tty, 104560); //Specifying a custom baud rate when using GNU C
	//cfsetospeed(tty, 104560);

	/*Other option for custom baud rate*/
	/*
		// #include <termios.h> This must be removed! 
		// Otherwise we'll get "redefinition of �struct termios�" errors
		#include <sys/ioctl.h> // Used for TCGETS2/TCSETS2, which is required for custom baud rates
		struct termios2 tty;
		// Read in the terminal settings using ioctl instead
		// of tcsetattr (tcsetattr only works with termios, not termios2)
		ioctl(fd, TCGETS2, tty);
		// Set everything but baud rate as usual
		// ...
		// ...

		// Set custom baud rate
		tty->c_cflag &= ~CBAUD;
		tty->c_cflag |= CBAUDEX;
		// On the internet there is also talk of using the "BOTHER" macro here:
		// tty->c_cflag |= BOTHER;
		// I never had any luck with it, so omitting in favour of using
		// CBAUDEX
		tty->c_ispeed = 123456; // What a custom baud rate!
		tty->c_ospeed = 123456;

		// Write terminal settings to file descriptor
		ioctl(*serial_port, TCSETS2, tty);
	*/
	
	// Save tty settings, also checking for error
	if (tcsetattr(*serial_port, TCSANOW, tty) != 0) {
		printf("Error %i from tcsetattr: %s\n", errno, strerror(errno));
	}
	/*********/
	/*WRITING*/
	/*********/
	//unsigned char msg[] = { 'H', 'e', 'l', 'l', 'o', '\r' };
	//write(*serial_port, msg, sizeof(msg));

	/*********/
	/*READING*/
	/*********/
	  // Allocate memory for read buffer, set size according to your needs
	//char read_buf [256];
	
	// Normally you wouldn't do this memset() call, but since we will just receive
	// ASCII data for this example, we'll set everything to 0 so we can
	// call printf() easily.
	//memset(&read_buf, '\0', sizeof(read_buf));
	
	// Read bytes. The behaviour of read() (e.g. does it block?,
	// how long does it block for?) depends on the configuration
	// settings above, specifically VMIN and VTIME
	//int num_bytes = read(*serial_port, &read_buf, sizeof(read_buf));
	
	// n is the number of bytes read. n may be 0 if no bytes were received, and can also be -1 to signal an error.
	//if (num_bytes < 0) {
	//	printf("Error reading: %s", strerror(errno));
	//	return 1;
	//}
	
	// Here we assume we received ASCII data, but you might be sending raw bytes (in that case, don't try and
	// print it to the screen like this!)
	//printf("Read %i bytes. Received message: %s", num_bytes, read_buf);

    //close(serial_port);

}



/*EXCLUSIVE ACCESS
prevent other processes from reading/writing to the serial port at the same time*/

/*#include <sys/file.h>

int main() {
    
    // ... get file descriptor here

    // Acquire non-blocking exclusive lock
    if(flock(fd, LOCK_EX | LOCK_NB) == -1) {
        throw std::runtime_error("Serial port with file descriptor " + 
            std::to_string(fd) + " is already locked by another process.");
    }

    // ... read/write to serial port here
}
*/

/*
  // See if there are bytes available to read
  int bytes;
  ioctl(fd, FIONREAD, &bytes);
*/
