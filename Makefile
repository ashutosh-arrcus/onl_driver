.PHONY: all    
all:
	make -C src
	make -C test
    
.PHONY: clean
clean:                                            
	make clean -C src
	make clean -C test
