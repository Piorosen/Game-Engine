#pragma once



struct Enviroment {
#ifdef OUTPUT_FILE
	static char directory[256];
	// "unit-test-result";
	static char fileName[256];

	// "%f-%day.txt"
	static char output[256];
#endif
#ifdef OUTPUT_CONSOLE


#endif
};


#ifdef OUTPUT_CONSOLE

void Config() {
	

}
#endif
#ifdef OUTPUT_FILE
void stringCopy(char* dest, const char* source) {
	while (*source != '\0') {
		*dest = *source;
		source++;
		dest++;
	}
	*dest = '\0';
}

void Config(const char* path, const char* fileName, const char* output) {
	stringCopy(Enviroment::directory, path);
	stringCopy(Enviroment::fileName, fileName);
	stringCopy(Enviroment::output, output);
}

#endif