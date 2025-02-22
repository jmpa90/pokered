import os

# Especifica la ruta del directorio que deseas explorar
ruta_directorio = r"C:\C++\pokered\engine\menus"

# Recorre el directorio y sus subdirectorios
for ruta, subdirectorios, archivos in os.walk(ruta_directorio):
    for archivo in archivos:
        # Imprime la ruta completa del archivo
        print(os.path.join(ruta, archivo))
