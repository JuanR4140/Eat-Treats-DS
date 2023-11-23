
@{{BLOCK(kitten)

@=======================================================================
@
@	kitten, 32x32@8, 
@	Transparent color : 00,00,00
@	+ palette 256 entries, not compressed
@	+ 16 tiles not compressed
@	Total size: 512 + 1024 = 1536
@
@	Time-stamp: 2023-11-23, 10:40:27
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global kittenTiles		@ 1024 unsigned chars
	.hidden kittenTiles
kittenTiles:
	.word 0x00000000,0x00000000,0x00000000,0x00050505,0x00000000,0x051C0500,0x00000000,0x1C1C0500
	.word 0x00000000,0x1C050000,0x00001700,0x05000000,0x17170000,0x05000000,0x00000000,0x05051717
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00050505,0x05050505,0x05051C1C,0x05050505
	.word 0x0505051C,0x05050505,0x00050005,0x05050505,0x15000505,0x05050505,0x00000505,0x05050505
	.word 0x00000000,0x00000000,0x00000000,0x05000000,0x00000505,0x1C050000,0x05050505,0x1C1C0505
	.word 0x05050505,0x051C1C05,0x05000500,0x051C0505,0x05150005,0x00050505,0x05000005,0x05050505
	.word 0x00000500,0x00000000,0x00000505,0x00000000,0x00000005,0x00000000,0x00000005,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00001717,0x17170000,0x00000000,0x00001717,0x00000000

	.word 0x00000000,0x17170000,0x00000000,0x05050000,0x00000000,0x17170000,0x17171700,0x05051717
	.word 0x00000000,0x17000000,0x00000000,0x00171700,0x00000000,0x00000017,0x17170000,0x00000000
	.word 0x05050505,0x05050505,0x05051717,0x051C1C05,0x05171717,0x051C0505,0x05051717,0x05050505
	.word 0x05050505,0x00000000,0x00050505,0x1C1C1C1C,0x00050505,0x1B1B1B1C,0x05050500,0x00000000
	.word 0x05050505,0x17170505,0x05050505,0x05051717,0x17170505,0x17171717,0x17050505,0x05050517
	.word 0x05050500,0x00171705,0x0505001C,0x17000505,0x0505001C,0x00000505,0x05050500,0x00000005
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x17171717,0x00001717
	.word 0x00000000,0x00000000,0x00000017,0x00000000,0x00171700,0x00000000,0x17000000,0x00000017

	.word 0x00001700,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x1B1B0000,0x1B1B1B1B,0x1B1B1B00,0x0800081B,0x05000000,0x00080005,0x05000000,0x05050505
	.word 0x05000000,0x06060505,0x05000000,0x06060505,0x05000000,0x06060505,0x05000000,0x06060505
	.word 0x1B1B1B1B,0x00000000,0x1B1B1B00,0x0000001B,0x00050508,0x00000000,0x00050505,0x00000000
	.word 0x00050505,0x00000000,0x00050505,0x00000000,0x00050505,0x00000000,0x00050505,0x00000000
	.word 0x00000000,0x00001700,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x17000000,0x17170000,0x18171717
	.word 0x18181700,0x18181818,0x17170000,0x19171717,0x00000000,0x19000000,0x00000000,0x00000000
	.word 0x05050500,0x06060505,0x05050500,0x06060505,0x05050517,0x06060505,0x05050518,0x06060505
	.word 0x05050518,0x06060505,0x05191919,0x19190505,0x19191919,0x19191919,0x00000000,0x00000000
	.word 0x05050505,0x00000005,0x05050505,0x00000005,0x05050505,0x17171705,0x05050505,0x18181805
	.word 0x05050505,0x18181805,0x19050505,0x19191919,0x19191919,0x19191919,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000017,0x00000000,0x17171718,0x00001717
	.word 0x18181818,0x00171818,0x17171719,0x00001717,0x00000019,0x00000000,0x00000000,0x00000000

	.section .rodata
	.align	2
	.global kittenPal		@ 512 unsigned chars
	.hidden kittenPal
kittenPal:
	.hword 0x0000,0x1884,0x1CA8,0x18EC,0x1D51,0x11DB,0x329B,0x4F1D
	.hword 0x1BDF,0x2B93,0x1AED,0x3646,0x15A9,0x112A,0x1CE6,0x38E7
	.hword 0x4186,0x71AB,0x7E6C,0x732B,0x7F79,0x7FFF,0x5AB3,0x41F0
	.hword 0x35AD,0x294B,0x450E,0x18D5,0x315B,0x5DFA,0x2651,0x19B1
	.hword 0x1084,0x1084,0x1084,0x1084,0x1084,0x1084,0x1084,0x1084
	.hword 0x14A5,0x14A5,0x14A5,0x14A5,0x14A5,0x14A5,0x14A5,0x14A5
	.hword 0x18C6,0x18C6,0x18C6,0x18C6,0x18C6,0x18C6,0x18C6,0x18C6
	.hword 0x1CE7,0x1CE7,0x1CE7,0x1CE7,0x1CE7,0x1CE7,0x1CE7,0x1CE7

	.hword 0x2108,0x2108,0x2108,0x2108,0x2108,0x2108,0x2108,0x2108
	.hword 0x2529,0x2529,0x2529,0x2529,0x2529,0x2529,0x2529,0x2529
	.hword 0x294A,0x294A,0x294A,0x294A,0x294A,0x294A,0x294A,0x294A
	.hword 0x2D6B,0x2D6B,0x2D6B,0x2D6B,0x2D6B,0x2D6B,0x2D6B,0x2D6B
	.hword 0x318C,0x318C,0x318C,0x318C,0x318C,0x318C,0x318C,0x318C
	.hword 0x35AD,0x35AD,0x35AD,0x35AD,0x35AD,0x35AD,0x35AD,0x35AD
	.hword 0x39CE,0x39CE,0x39CE,0x39CE,0x39CE,0x39CE,0x39CE,0x39CE
	.hword 0x3DEF,0x3DEF,0x3DEF,0x3DEF,0x3DEF,0x3DEF,0x3DEF,0x3DEF

	.hword 0x4210,0x4210,0x4210,0x4210,0x4210,0x4210,0x4210,0x4210
	.hword 0x4631,0x4631,0x4631,0x4631,0x4631,0x4631,0x4631,0x4631
	.hword 0x4A52,0x4A52,0x4A52,0x4A52,0x4A52,0x4A52,0x4A52,0x4A52
	.hword 0x4E73,0x4E73,0x4E73,0x4E73,0x4E73,0x4E73,0x4E73,0x4E73
	.hword 0x5294,0x5294,0x5294,0x5294,0x5294,0x5294,0x5294,0x5294
	.hword 0x56B5,0x56B5,0x56B5,0x56B5,0x56B5,0x56B5,0x56B5,0x56B5
	.hword 0x5AD6,0x5AD6,0x5AD6,0x5AD6,0x5AD6,0x5AD6,0x5AD6,0x5AD6
	.hword 0x5EF7,0x5EF7,0x5EF7,0x5EF7,0x5EF7,0x5EF7,0x5EF7,0x5EF7

	.hword 0x6318,0x6318,0x6318,0x6318,0x6318,0x6318,0x6318,0x6318
	.hword 0x6739,0x6739,0x6739,0x6739,0x6739,0x6739,0x6739,0x6739
	.hword 0x6B5A,0x6B5A,0x6B5A,0x6B5A,0x6B5A,0x6B5A,0x6B5A,0x6B5A
	.hword 0x6F7B,0x6F7B,0x6F7B,0x6F7B,0x6F7B,0x6F7B,0x6F7B,0x6F7B
	.hword 0x739C,0x739C,0x739C,0x739C,0x739C,0x739C,0x739C,0x739C
	.hword 0x77BD,0x77BD,0x77BD,0x77BD,0x77BD,0x77BD,0x77BD,0x77BD
	.hword 0x7BDE,0x7BDE,0x7BDE,0x7BDE,0x7BDE,0x7BDE,0x7BDE,0x7BDE
	.hword 0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x7FFF

@}}BLOCK(kitten)