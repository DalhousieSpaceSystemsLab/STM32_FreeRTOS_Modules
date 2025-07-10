let 
        nixpkgs = fetchTarball "https://github.com/NixOS/nixpkgs/tarball/nixos-25.05";
        pkgs = import nixpkgs { config.allowUnfree = true; overlays = []; };
in
        pkgs.mkShellNoCC {
                packages = with pkgs; [
				# Basic Requirements for CMake
                        gcc-arm-embedded
                        cmake
                        openocd
                # Requirements for STM32
                        stlink
                        stlink-gui
                        stm32cubemx
                        # Requirements for Protobuf
                        nanopb
                        abseil-cpp
                # Extras
                        vim
                        screen #Read serial output from UART
                ];

                shellHook = ''
                        export PKG_CONFIG_PATH="${pkgs.protobuf}/lib/pkgconfig:$PKG_CONFIG_PATH"
                        export CMAKE_PREFIX_PATH="${pkgs.protobuf}:$CMAKE_PREFIX_PATH"
                '';
        }