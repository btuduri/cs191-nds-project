#pragma once

#ifndef EXTERN_H_
#define EXTERN_H_

volatile int frame = 0;

void Vblank() {
	frame++;
}

#endif /*EXTERN_H_*/
