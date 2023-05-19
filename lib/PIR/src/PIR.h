/** \addtogroup PIRGeneric
 *  @{
 */

#ifndef PIR_H
#define PIR_H

#include <Arduino.h>

class PIR
{
	public:
		explicit PIR(int PIRPin);
		bool read();             
	private:
		const int signalPin;
};
#endif //PIR_H
/** @}*/