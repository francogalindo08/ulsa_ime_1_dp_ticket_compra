# Práctica: Ticket de compra

> Llena cada sección en la fase que se indica. Las instrucciones completas están en `PRACTICA.md`.
> Si una pregunta no aplica (por ejemplo, no hiciste el Experimento C o no tuviste dudas), escribe `No aplica`. Si te sobran filas en una tabla, bórralas.

## 1. Descripción del problema (Fase 1)
<!-- Explica con tus palabras qué hace tu programa y para qué serviría en la vida real. Máximo 4 líneas. -->
El programa sirve para generar el ticket de compra de un producto. Pide el nombre, el precio unitario, la cantidad comprada y el porcentaje de descuento, y calcula el subtotal, el descuento, el IVA y el total a pagar. En la vida real serviría en la caja de una tienda para cobrar y entregar el comprobante al cliente.

## 2. Entradas y salidas (Fase 1)
<!-- Define cada entrada y cada salida, con su tipo de dato y la función de utilerias.h con la que la vas a leer. -->

**Entradas:**

| Entrada | Tipo de dato | Función de `utilerias.h` |
|---|---|---|
| nombre del producto | string | leerCadena |
| precio | double | leerDecimal |
| cantidad | int | leerEntero |
| descuento (%) | double | leerDecimal |

**Salida** (¿qué datos muestra el ticket?):
Producto, cantidad, precio unitario, subtotal, descuento, IVA y total.

**¿El IVA se calcula sobre el subtotal o sobre lo que queda después del descuento? ¿Por qué?**
El IVA se calcula sobre lo que queda después del descuento, es decir, sobre el subtotal menos el descuento, porque el impuesto se cobra sobre el monto que realmente paga el cliente.

## 3. Restricciones e invariante (Fases 1 y 2)

**Restricciones** (¿qué debe cumplirse?):

| Dato | ¿Qué valores son válidos? | ¿Por qué? |
|---|---|---|
| Nombre del producto | Texto con al menos un carácter que no sea espacio | Un producto sin nombre no se puede identificar en el ticket |
| Precio | Número mayor que 0 | Un producto no puede costar cero ni un valor negativo |
| Cantidad | Entero mayor que 0 | No se pueden comprar 0 piezas, piezas negativas ni media pieza |
| Descuento (%) | Número entre 0 y 100 | Un descuento negativo subiría el precio y uno mayor a 100 dejaría un total negativo |

**¿Qué hace mi programa si el usuario escribe un dato fuera de rango?**
Muestra un mensaje de error y vuelve a pedir el dato, repitiendo el ciclo hasta que el valor sea válido.

**¿Puede el total salir negativo? ¿Por qué?**
No. Como el descuento está entre 0 y 100 %, el descuento nunca supera al subtotal, así que (subtotal − descuento) siempre es mayor o igual a 0, y el IVA tampoco es negativo.

**Invariante 1** (después del ciclo que valida el precio, ¿qué es siempre cierto sobre `precio`?):
Que `precio` es un número válido (finito) y mayor que 0.

**Invariante 2** (¿qué relación se cumple siempre entre el subtotal, el descuento, el IVA y el total?):
total = subtotal − descuento + IVA, con 0 ≤ descuento ≤ subtotal, por lo que el total nunca es negativo.


## 4. Tipo de dato abstracto (Fase 1)

| TDA | Datos (¿qué tiene?) | Operaciones (¿qué se puede hacer con él?) |
|---|---|---|
| Producto | nombre (texto), precio unitario (decimal), cantidad (entero) | calcular su subtotal |
| Ticket | producto, subtotal, descuento, IVA, total | calcular los importes, imprimirse |

**Jerarquías:** una tienda vende productos por pieza (un cuaderno) y productos por peso (un kilo de tortillas). ¿Los dos son productos? ¿Qué datos tienen en común y cuál cambia?
Sí, los dos son productos. Tienen en común el nombre y el precio unitario. Lo que cambia es la cantidad: en el producto por pieza es un entero (número de piezas) y en el producto por peso es un decimal (kilos), y el precio unitario es por pieza o por kilo según el caso.

## 6. Análisis descendente (Fase 2)
<!-- Completa el árbol. Marca con (ya existe) las partes que ya resuelve una función de utilerias.h o de ticket.h. -->

```
Generar ticket de compra
├── 1. Mostrar bienvenida
├── 2. Pedir los datos
│     ├── 2.1 Pedir el nombre del producto (ya existe: leerCadena)
│     ├── 2.2 Pedir el precio (y validar que sea un número mayor que 0)
│     ├── 2.3 Pedir la cantidad (y validar que sea un entero mayor que 0)
│     └── 2.4 Pedir el descuento (y validar que esté entre 0 y 100)
├── 3. Calcular los importes
│     ├── 3.1 Calcular el subtotal (ya existe: calcularSubtotal)
│     ├── 3.2 Calcular el descuento (ya existe: calcularDescuento)
│     ├── 3.3 Calcular el IVA sobre el subtotal menos el descuento
│     └── 3.4 Calcular el total
└── 4. Imprimir el ticket
```

**Análisis ascendente: ¿qué partes del árbol ya estaban resueltas por una función que existe? ¿Cuáles?**
Leer los datos (`leerCadena`, `leerEntero` y `leerDecimal` de `utilerias.h`), calcular el subtotal (`calcularSubtotal`), calcular el descuento (`calcularDescuento`) y dibujar las líneas del ticket (`imprimirLinea`).

**¿Alguna parte del árbol hacía más de una cosa? ¿Cómo la dividiste?**
Sí, "Pedir los datos" y "Calcular los importes" hacían varias cosas. Las dividí en un paso por cada dato que se pide y un paso por cada importe que se calcula (subtotal, descuento, IVA y total).

## 7. Módulos y receta (Fase 2)

| Módulo | ¿Qué recibe? | ¿Qué devuelve? | ¿Función o procedimiento? |
|---|---|---|---|
| `calcularSubtotal` | precio, cantidad | el subtotal | Función |
| `calcularDescuento` | subtotal, porcentaje | el monto del descuento | Función |
| `calcularIVA` | el monto sobre el que se calcula (subtotal − descuento) y la tasa de IVA | el monto del IVA | Función |
| `imprimirTicket` | producto, cantidad, precio, subtotal, descuento, IVA y total | nada (solo muestra el ticket en pantalla) | Procedimiento |
| `calcularPorcentaje` | un monto y un porcentaje (0 a 100) | el monto que corresponde a ese porcentaje | Función |

<!-- Tu receta va en el archivo RECETA.md. Aquí solo responde las preguntas. -->

**¿Probé mi receta a mano con mis 3 casos?** Sí / No
**¿Tuve que corregirla? ¿Qué cambié?** _____

## 8. Cómo compilar y ejecutar (Fase 3)

Compilar (desde la carpeta del proyecto):

```bash
g++ -Wall -Wextra -std=c++17 -Iinclude src/main.cpp -o ticket
```

Ejecutar en macOS:

```bash
./ticket
```

Ejecutar en Windows:

```bash
.\ticket.exe
```

**¿En qué sistema operativo trabajé?** _____

## 9. Ejemplo de ejecución (Fase 3)
<!-- Pega aquí lo que muestra tu programa en pantalla con el caso 2 de la tabla de pruebas (Cuaderno, 50, 2, 10). -->

```
_____
```

## 10. De la receta al código (Fase 3)
<!-- Para cada paso de TU receta, escribe el módulo o la instrucción de C++ que lo implementa. Agrega las filas que necesites. -->

| Paso de la receta | Módulo o instrucción de C++ que lo implementa |
|---|---|
| 1. Mensaje de bienvenida | `std::cout << "Bienvenido a la tienda\n";` |
| 2. Leer el producto | `producto = leerCadena("Escribe el producto: ");` |
| 3. Leer y validar la cantidad | ciclo `do { ... } while (cantidad <= 0);` con `leerEntero` |
| 4. Leer y validar el precio | ciclo `do { ... } while (precio <= 0.0);` con `leerDecimal` |
| 5. Leer y validar el descuento | ciclo `do { ... } while (porcentaje < 0 \|\| porcentaje > 100);` con `leerDecimal` |
| 6. Calcular el subtotal | `subtotal = calcularSubtotal(precio, cantidad);` |
| 7. Calcular el descuento | `descuento = calcularDescuento(subtotal, porcentaje);` |
| 8. Calcular el IVA | `impuesto = (subtotal - descuento) * IVA;` |
| 9. Calcular el total | `total = (subtotal - descuento) + impuesto;` |
| 10. Imprimir el ticket | `std::cout` de cada renglón con `imprimirLinea(20, '=');` entre ellos |

**¿Hubo algún paso de mi receta que me costó traducir a C++? ¿Cuál y por qué?**
_____

**Formato del ticket: ¿qué ancho usé en `std::setw` y por qué? ¿Qué pasa si uso un número menor que el largo de la etiqueta más larga?**
_____

**¿Convertí el ancho de las líneas del ticket (36) en una constante? ¿Cómo la llamé? Si no, ¿por qué?**
_____

## 11. Experimentos y depuración (Fase 3)

**Experimento A: depuración de `calcularDescuento`**

| Paso de depuración | Lo que hice o encontré |
|---|---|
| 1. Reproduce: ¿con qué datos falló? | Con un descuento distinto de 0, por ejemplo subtotal 100 y descuento 10 %, el descuento salía 1000 en lugar de 10 |
| 2. Aísla: ¿qué valor intermedio estaba mal? (salidas `[DEBUG]`) | El valor de `porcentaje` que llegaba a la función: era 10 y la función lo multiplicaba directo por el subtotal |
| 3. Explica: ¿cuál era la causa? | La función recibe el porcentaje de 0 a 100 pero no lo dividía entre 100 |
| 4. Corrige: ¿qué cambiaste? | `return subtotal * (porcentaje / 100.0);` |
| 5. Limpia: ¿comentaste tus salidas `[DEBUG]`? | _____ |

**La prueba con 0 % pasó aunque la función tenía un error. ¿Qué me enseña eso sobre elegir mis casos de prueba?**
Con 0 % el resultado es 0 sin importar si se divide entre 100 o no (subtotal × 0 = 0), así que ese caso no detecta el error. Hay que elegir casos que usen valores distintos de 0 y de los extremos, como 10 % o 15 %, para que el cálculo realmente se ejercite.

**Experimento B: al cambiar el IVA a 8 %, ¿cuántas líneas tuve que cambiar? ¿Qué mejoraría?**
_____

**¿Mi ticket seguía diciendo `IVA (16%)`? ¿Qué hice al respecto?**
_____

**Experimento C (opcional): al cambiar el parámetro dentro de `calcularIVA`, ¿cambió la variable de `main()`? ¿Por qué?**
_____

## 12. La constante "Le atendio" (Fase 3)

**¿Dónde definí la constante con mi nombre?** (marca una)
- [ ] Constante local dentro de `imprimirTicket`
- [ ] Constante a nivel de la librería, en `ticket.h`
- [ ] Función que siempre devuelve la misma cadena

**¿Por qué elegí esa opción?**
_____

**¿Qué otras partes del programa podrían necesitar el nombre de quien atiende? (un mensaje de bienvenida, un ticket de devolución...)**
_____

**Si mañana atiende otra persona, ¿en cuántos lugares tengo que cambiar el nombre?**
_____

**Si el nombre se leyera del teclado o de un archivo, ¿cuánto código tendría que cambiar con mi opción?**
_____

## 13. Tabla de pruebas (Fase 4)
<!-- Los datos de entrada de cada caso están en PRACTICA.md, Fase 4. -->

| # | Caso | Esperado (subtotal / descuento / IVA / total) | Obtenido | ¿Pasó? |
|---|---|---|---|---|
| 1 | Sin descuento | 100.00 / 0.00 / 16.00 / 116.00 | _____ | _____ |
| 2 | Con descuento | 100.00 / 10.00 / 14.40 / 104.40 | _____ | _____ |
| 3 | Descuento de 15 % | 600.00 / 90.00 / 81.60 / 591.60 | _____ | _____ |
| 4 | Precio con centavos | 19.99 / 0.00 / 3.20 / 23.19 | _____ | _____ |
| 5 | Descuento total | 90.00 / 90.00 / 0.00 / 0.00 | _____ | _____ |
| 6 | Precio inválido | vuelve a pedir el precio dos veces; 40.00 / 0.00 / 6.40 / 46.40 | _____ | _____ |
| 7 | Cantidad inválida | vuelve a pedir la cantidad dos veces; 20.00 / 0.00 / 3.20 / 23.20 | _____ | _____ |
| 8 | Descuento inválido | vuelve a pedir el descuento dos veces; 100.00 / 20.00 / 12.80 / 92.80 | _____ | _____ |
| 9 | Texto en el precio | vuelve a pedir el precio una vez; 100.00 / 0.00 / 16.00 / 116.00 | _____ | _____ |
| 10 | Nombre con espacios | muestra el nombre completo; 25.50 / 0.00 / 4.08 / 29.58 | _____ | _____ |
| 11 | Nombre vacío | vuelve a pedir el nombre una vez; 12.00 / 0.00 / 1.92 / 13.92 | _____ | _____ |
| 12 | Caso propio 1: Lápiz, precio 3.50, cantidad 100, descuento 0 | 350.00 / 0.00 / 56.00 / 406.00 | _____ | _____ |
| 13 | Caso propio 2: Libreta, precio 80, cantidad 2, descuento 12.5 | 160.00 / 20.00 / 22.40 / 162.40 | _____ | _____ |

**En el caso 4 el IVA real es 3.1984. ¿Por qué mi ticket muestra 3.20?**
Porque al imprimir se muestran solo 2 decimales y el valor se redondea al mostrarlo; internamente la variable sigue guardando 3.1984.

**En el caso 10, ¿el ticket siguió alineado? Si no, ¿qué corregí?**
_____

## 14. Generalización (Fase 4)

**¿Qué cálculo hacen `calcularDescuento` y `calcularIVA`? ¿Qué cambia entre una y otra?**
Las dos calculan un porcentaje de un monto: monto × (porcentaje ÷ 100). Lo que cambia es el monto base (el subtotal en el descuento y el subtotal menos el descuento en el IVA) y el porcentaje que se aplica (el que escribe el usuario en el descuento y la tasa de IVA en el impuesto).

**Receta de `calcularPorcentaje`** (también va en `RECETA.md`):

```text
Recibe: un monto y un porcentaje (de 0 a 100).
Devuelve: el monto que corresponde a ese porcentaje.

1. Recibir el monto y el porcentaje.
2. Dividir el porcentaje entre 100 para convertirlo a decimal.
3. Multiplicar el monto por ese decimal.
4. Devolver el resultado.
```

**¿Cómo quedaron el descuento y el IVA después del cambio?**
__bien___

**¿Volví a correr toda la tabla de pruebas después del cambio? ¿Todo siguió pasando?**
___si__

**¿Agregué `calcularPorcentaje` a mi tabla de módulos (sección 7)?** Sí 

**¿En qué otro programa podría reutilizar `calcularPorcentaje`?**
En un programa de propinas, de comisiones de ventas, de intereses de un préstamo o de calificaciones (porcentaje de aciertos de un examen).

## 15. Revisión de calidad (Fase 4)

| Principio | Pregunta | ¿Lo cumple? | Evidencia |
|---|---|---|---|
| Correcto | ¿Pasa todas las pruebas de la tabla? | __si___ | _____ |
| Robusto | ¿Resiste datos inválidos sin fallar ni termisnar? | __si___ | _____ |
| Legible | ¿Otra persona entiende tu código sin que se lo expliques? | __no se___ | _____ |
| Modular | ¿Cada función hace una sola cosa? | __si___ | _____ |
| Sin números mágicos | ¿Los valores fijos tienen nombre? | _si____ | _____ |
| Fácil de mantener | Si cambia el IVA o quien atiende, ¿cuántas líneas cambias? | _una____ | _____ |
| Reutilizable | ¿Alguna de tus funciones serviría en otro programa? | ___si__ | _____ |

## 16. Reto obligatorio (Fase 4)

**¿Qué reto elegí?** (número y nombre; el 4 no cuenta como obligatorio) 

**¿Por qué lo elegí?**
____nomas_

**¿Cómo lo resolví? ¿Qué módulos agregué o cambié?**
____ninugno_

**¿Hice algún otro reto opcional? ¿Cuál?**
___no__

## 17. Bitácora de mejoras (Fase 4)

| # | ¿Qué falló o qué quise mejorar? | ¿Qué cambié? | ¿Funcionó? |
|---|---|---|---|
| 1 | El descuento salía mal porque `calcularDescuento` no dividía el porcentaje entre 100 | Cambié la función a `subtotal * (porcentaje / 100.0)` y quité la división de `main` | __si___ |
| 2 | _____ | _____ | _____ |

## 18. Dudas para el profesor (Fase 3)

| Duda | Lo que ya intenté |
|---|---|
| _____ | _____ |

## 19. Reflexión final

**¿Qué aprendí con esta práctica?**
___orden y limpieza__

**Ahora que terminé, ¿qué cambiaría de mi proceso?**
___no estresarme __

**¿Qué fue lo más difícil y cómo lo resolví?**
__la logica ___

**¿Qué pregunta me quedó sin responder?**
___no_

**Comparado con las prácticas anteriores, donde todo estaba en `main()`, ¿dividir el programa en módulos me facilitó o me complicó el trabajo? ¿Por qué?**
____complico _

**¿Cómo encontré el error de `calcularDescuento`? ¿Lo habría encontrado si solo hubiera probado sin descuento?**
__leyendo ___

## 20. Commits (Fase 5)

**¿Cuántos commits hice durante la práctica?** ___2 - 3__

**Si hice menos de 3, ¿por qué?**
__poq soy muy bueno ___

## 21. Lista de verificación antes de entregar (Fase 5)

- [ ] Llené las secciones 1 a 20 (no quedan `_____`; escribí `No aplica` donde corresponde)
- [ ] Completé el árbol de análisis descendente y la tabla de módulos
- [ ] Escribí en `RECETA.md` la receta de `main` y la de cada módulo, antes de programar
- [ ] Cada bloque de `main.cpp` tiene su comentario `// Paso N`, de acuerdo con mi receta
- [ ] Corregí el error de `calcularDescuento` y documenté cómo lo encontré
- [ ] Hice los Experimentos A y B y dejé el código correcto al terminar
- [ ] Mi ticket se ve alineado y termina con la línea "Le atendio:", leída de una constante
- [ ] Justifiqué dónde definí la constante con mi nombre
- [ ] Escribí `calcularPorcentaje` y volví a correr todas las pruebas
- [ ] Hice al menos uno de los retos y lo documenté
- [ ] No queda ninguna salida `[DEBUG]` activa
- [ ] Mi programa compila sin advertencias
- [ ] Probé todos los casos de la tabla
- [ ] Revisé los principios de calidad de mi programa
- [ ] No modifiqué `utilerias.h`
- [ ] Tengo al menos 3 commits con mensajes claros (o justifiqué por qué no)
- [ ] Hice `git push` y verifiqué mi fork en GitHub
- [ ] Mi fork se llama `ulsa_ime_1_dp_ticket_compra`, mis módulos están en `include/ticket.h` y mi programa principal en `src/main.cpp`
- [ ] Entregué el enlace de mi fork en Classroom