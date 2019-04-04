# ofxInteractivo
Utils para el diseño interactivo prolijo

Requiere ofxJSON,ofxSVG

# MODULOS (ESTO ESTA VIEJO NI LEER MIRAR EL EJEMPLO)

ofxInteractivoHid
Todo lo que tenga que ver con interfaz humana, por ahora cachea el mouse, tengo que agregarle touch

ofxInteractivoColorPalette
Todas las funciones realacionadas a manejo de color

ofxInteractivoFont
Todas las funciones relaciones al manejo de fonts

# NUEVO

Ahora lo que antes era "EM" se llama APP.
Lo que antes era EM::add_font() , ahora es APP::font.add(), asi con todos los modulos.

# HID
No hay que usar mas ofGetMouse ...
Ahora tenemos APP::hid.x , APP::hid.y , APP::hid.pressed()
Y una interesante APP::hid.bang_pressed(), que se ejecuta solo cuando se hace click y no mientras este se mantiene. Onda evento.
Habria que pensarle otro nombre.


# TODO 

Refactorear un poco EM e integrarlo

# IDEAS

Agregar "defines" para prender y apagar modulos pesados, como Syphon, Spout y demas. Generar un .h donde esten estos includes
dependiendo la necesidad, o plataforma, elegir usarlos o no, y crear modulos con shortcuts para cada uno.
