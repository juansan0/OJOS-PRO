# OJOS-PRO

Esta es una librería de software libre que te permitirá controlar un display OLED de 128x64 píxeles y mostrar animaciones de ojos. Esta librería es compatible con una amplia gama de microcontroladores y plataformas de desarrollo, y es fácil de integrar en tus proyectos.
La librería incluye varias animaciones predefinidas para los ojos.

Para empezar a utilizar esta librería, descarga el repositorio y sigue los siguientes pasos:

	1-Instala la librería en tu plataforma de desarrollo.
	2-Conecta el display OLED a tu plataforma de desarrollo según las instrucciones del fabricante.
	3-Incluye la librería en tu proyecto y utiliza las funciones proporcionadas para controlar el display y mostrar las animaciones de ojos.

## Vista previa en terminal para desarrollo

Además del uso con hardware real, esta librería ahora incluye una vista previa nativa en terminal para previsualizar las animaciones de ojos directamente en la consola, sin necesidad de una pantalla OLED ni de una placa Arduino conectada. Esto permite iterar más rápido sobre los cuadros y la lógica de animación durante el desarrollo.

Requisitos:

- Un compilador compatible con C++11, como `g++`, sin necesidad de Arduino IDE ni del toolchain de Arduino para esta ruta de vista previa.

Cómo compilar y ejecutar:

- `make` o `make terminal` construye la aplicación de vista previa en `./bin/ojos_pro_terminal`.
- `./bin/ojos_pro_terminal` la ejecuta.
- `make run` hace la compilación y la ejecución en un solo paso.
- `make clean` elimina la salida generada en `bin/`.

Uso básico:

- Al ejecutarse, la CLI muestra un menú numerado con las expresiones disponibles (normales, enojados, preocupados, relajados, sorprendidos, atentos, guino). `ejemplo()` sigue siendo solo para hardware y no está disponible aquí.
- Puedes elegir una expresión, reproducirla en bucle o avanzar cuadro a cuadro (presionando Enter para cada frame, y `q` + Enter para detener antes de tiempo).
- En el modo de reproducción en bucle puedes elegir reproducir una vez o repetir hasta presionar Ctrl+C.

Esta vista previa no afecta ni requiere cambios en tus sketches reales de Arduino: el uso existente (`OJOS_PRO ojos; ojos.begin(); ...`) sigue funcionando igual en hardware real. La vista previa en terminal es solo una herramienta adicional y opcional para el desarrollo.
