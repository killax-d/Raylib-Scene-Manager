include cfg/makeconf

# Build game binaries
all:
	@make -C src

# Adding binary file and desktop related icons/launcher
install:
	cp -f $(APP) /usr/games/$(APP)
	
	mkdir -p /usr/share/$(APP)
	mkdir -p ~/.local/share/applications
	
	cp -rf res/* /usr/share/$(APP)
	
	cp -f conf/$(APP).desktop /usr/share/applications
	
	update-desktop-database /usr/share/applications

# Removing binary file and desktop related icons/launcher
uninstall:
	rm -rf /usr/games/$(APP)
	
	rm -rf /usr/share/$(APP)
	
	rm -rf /usr/share/applications/$(APP).desktop
	update-desktop-database /usr/share/applications

# Clean up *.o files
clean:
	@make -C src clean

# Clean up *.o files and game binary
purge:
	@make -C src purge