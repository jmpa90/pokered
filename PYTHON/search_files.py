
import os

# Especifica la ruta del directorio que deseas explorar
ruta_directorio = r"C:\C++\pokered"

# Recorre el directorio y sus subdirectorios
for ruta, subdirectorios, archivos in os.walk(ruta_directorio):
    for subdirectorio in subdirectorios:
        # Imprime la ruta completa del subdirectorio
        print(os.path.join(ruta, subdirectorio))


