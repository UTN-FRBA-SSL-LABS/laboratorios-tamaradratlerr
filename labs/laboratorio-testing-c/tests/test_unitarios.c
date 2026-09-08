#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/* ═══════════════════════════════════════════════════════════════════════════
 *  TESTS ESCRITOS — ya funcionan, son el punto de partida
 * ═══════════════════════════════════════════════════════════════════════════ */

void test_carrito_nuevo(void) {
    printf("\n[carrito nuevo]\n");
    Carrito c;
    carrito_init(&c);
    ASSERT_IGUAL(0, carrito_contar(&c));
}

void test_agregar_uno(void) {
    printf("\n[agregar un producto]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Leche", 350, 1};
    ASSERT_IGUAL(1, carrito_agregar(&c, p));   /* devuelve 1 = exito */
    ASSERT_IGUAL(1, carrito_contar(&c));
}

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE A — Agregar el siguiente test (ver README.md, Parte 4)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: pegar aqui la funcion test_total_precio_unitario() */
void test_total_precio_unitario(void) {
    printf("\n[total: un producto, cantidad 1]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Leche", 350, 1};
    carrito_agregar(&c, p);
    ASSERT_IGUAL(350, carrito_total(&c));
}

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE B — Completar los blancos (ver README.md, Parte 5)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: pegar y completar la funcion test_total_con_cantidad() */
void test_total_con_cantidad(void) {
    printf("\n[total: un producto, cantidad 2]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Leche", 350, 2};  /* 350 x 2 = 700 */
    carrito_agregar(&c, p);
    ASSERT_IGUAL(700, carrito_total(&c));
}

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE C — Escribir un test propio (ver README.md, Parte 7)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: escribir test_carrito_lleno() */
void test_carrito_lleno(void) {
    printf("\n[carrito lleno: rechaza el 5to producto]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Leche", 350, 1};

    /* Lleno el carrito hasta MAX_ITEMS */
    for (int i = 0; i < MAX_ITEMS; i++) {
        carrito_agregar(&c, p);
    }
    ASSERT_IGUAL(MAX_ITEMS, carrito_contar(&c));

    /* El 5to intento debe fallar y devolver 0 */
    ASSERT_IGUAL(0, carrito_agregar(&c, p));
}

void test_descuento(void) {
    printf("\n[descuento porcentual]\n");
    ASSERT_IGUAL(900,  carrito_descuento(1000, 10));  /* 10% de 1000 */
    ASSERT_IGUAL(1000, carrito_descuento(1000, 0));   /* sin descuento */
    ASSERT_IGUAL(0,    carrito_descuento(1000, 100)); /* todo gratis */
}

/* ═══════════════════════════════════════════════════════════════════════════
 *  main
 * ═══════════════════════════════════════════════════════════════════════════ */

int main(void) {
    printf("=== Tests unitarios ===");
    test_carrito_nuevo();
    test_agregar_uno();
    /* Descomentar a medida que agregues las funciones: */
    test_total_precio_unitario();
    test_total_con_cantidad();    
    test_carrito_lleno();  
    test_descuento();      
    RESUMEN();
    return EXIT_CODE();
}
