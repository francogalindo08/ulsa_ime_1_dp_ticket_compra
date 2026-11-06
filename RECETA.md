# Receta: Ticket de compra

<!-- Escribe aquí tus recetas en pseudocódigo, ANTES de programar.
     Primero la receta del programa principal (main) y después una receta corta para cada módulo que vas a escribir tú.
     El primer paso de main es solo un ejemplo del formato; el resto es tuyo.
     Si las corriges después de probarlas a mano, deja aquí la versión final. -->

## Receta del programa principal (`main`)

<!-- Debe leerse casi igual que tu árbol de análisis descendente (sección 6 del README). -->

```text

1-Declarar las variables y la constante IVA = 0.16.
2-Mostrar el mensaje “Bienvenido a la tienda”.
3-Leer el producto (el texto no puede quedar vacío).
4-Leer la cantidad:
5-Repetir mientras cantidad ≤ 0, mostrando el mensaje de error.
6-Leer el precio:
7-Repetir mientras precio ≤ 0, mostrando el mensaje de error.
8-Leer el descuento:
9-Repetir mientras porcentaje < 0 o porcentaje > 100, mostrando el mensaje de error.
10-Calcular el subtotal:
subtotal = precio × cantidad
Calcular el descuento (en pesos):
descuento = subtotal × (porcentaje ÷ 100)
Calcular el IVA sobre el monto ya descontado:
impuesto = (subtotal − descuento) × IVA
11-Calcular el total:
total = (subtotal − descuento) + impuesto
12-Imprimir el ticket, con una línea de = entre cada renglón:
Producto
Cantidad
Precio unitario
Subtotal
Descuento
IVA
Total
Terminar el programa.

```

## Recetas de los módulos

<!-- Para cada módulo: qué recibe, qué hace y qué devuelve. -->

### `calcularIVA`

```text
MODULO calcularIVA(_____)

FIN MODULO
```

### `imprimirTicket`

```text
MODULO imprimirTicket(_____)

FIN MODULO
```

### `calcularPorcentaje` (Fase 4)

```text
MODULO calcularPorcentaje(_____)

FIN MODULO
```

### Otros módulos que agregues (por ejemplo, para tu reto)

```text

```
