#include <idt.h>
#include <ihc.h>

#define SETUP_IDT(n) \
    idt[n].offset_1 = ((uintn)ihc##n) & 0xffff; \
    idt[n].selector = get_cs(); \
    idt[n].ist = 0; \
    idt[n].type_attributes = 0x8e; \
    idt[n].offset_2 = (((uintn) ihc##n) >> 16) & 0xffff; \
    idt[n].offset_3 = ((uintn) ihc##n) >> 32;

intd_t idt[256];

u16 get_cs(void) {
    return 8;
    u16 cs;
    asm volatile("mov %%cs, %0" : "=r"(cs));
    return cs;
}

void idt_init()
{
    SETUP_IDT(0)
    SETUP_IDT(1)
    SETUP_IDT(2)
    SETUP_IDT(3)
    SETUP_IDT(4)
    SETUP_IDT(5)
    SETUP_IDT(6)
    SETUP_IDT(7)
    SETUP_IDT(8)
    SETUP_IDT(9)
    SETUP_IDT(10)
    SETUP_IDT(11)
    SETUP_IDT(12)
    SETUP_IDT(13)
    SETUP_IDT(14)
    SETUP_IDT(15)
    SETUP_IDT(16)
    SETUP_IDT(17)
    SETUP_IDT(18)
    SETUP_IDT(19)
    SETUP_IDT(20)
    SETUP_IDT(21)
    SETUP_IDT(22)
    SETUP_IDT(23)
    SETUP_IDT(24)
    SETUP_IDT(25)
    SETUP_IDT(26)
    SETUP_IDT(27)
    SETUP_IDT(28)
    SETUP_IDT(29)
    SETUP_IDT(30)
    SETUP_IDT(31)
    SETUP_IDT(32)
    SETUP_IDT(33)
    SETUP_IDT(34)
    SETUP_IDT(35)
    SETUP_IDT(36)
    SETUP_IDT(37)
    SETUP_IDT(38)
    SETUP_IDT(39)
    SETUP_IDT(40)
    SETUP_IDT(41)
    SETUP_IDT(42)
    SETUP_IDT(43)
    SETUP_IDT(44)
    SETUP_IDT(45)
    SETUP_IDT(46)
    SETUP_IDT(47)
    SETUP_IDT(48)
    SETUP_IDT(49)
    SETUP_IDT(50)
    SETUP_IDT(51)
    SETUP_IDT(52)
    SETUP_IDT(53)
    SETUP_IDT(54)
    SETUP_IDT(55)
    SETUP_IDT(56)
    SETUP_IDT(57)
    SETUP_IDT(58)
    SETUP_IDT(59)
    SETUP_IDT(60)
    SETUP_IDT(61)
    SETUP_IDT(62)
    SETUP_IDT(63)
    SETUP_IDT(64)
    SETUP_IDT(65)
    SETUP_IDT(66)
    SETUP_IDT(67)
    SETUP_IDT(68)
    SETUP_IDT(69)
    SETUP_IDT(70)
    SETUP_IDT(71)
    SETUP_IDT(72)
    SETUP_IDT(73)
    SETUP_IDT(74)
    SETUP_IDT(75)
    SETUP_IDT(76)
    SETUP_IDT(77)
    SETUP_IDT(78)
    SETUP_IDT(79)
    SETUP_IDT(80)
    SETUP_IDT(81)
    SETUP_IDT(82)
    SETUP_IDT(83)
    SETUP_IDT(84)
    SETUP_IDT(85)
    SETUP_IDT(86)
    SETUP_IDT(87)
    SETUP_IDT(88)
    SETUP_IDT(89)
    SETUP_IDT(90)
    SETUP_IDT(91)
    SETUP_IDT(92)
    SETUP_IDT(93)
    SETUP_IDT(94)
    SETUP_IDT(95)
    SETUP_IDT(96)
    SETUP_IDT(97)
    SETUP_IDT(98)
    SETUP_IDT(99)
    SETUP_IDT(100)
    SETUP_IDT(101)
    SETUP_IDT(102)
    SETUP_IDT(103)
    SETUP_IDT(104)
    SETUP_IDT(105)
    SETUP_IDT(106)
    SETUP_IDT(107)
    SETUP_IDT(108)
    SETUP_IDT(109)
    SETUP_IDT(110)
    SETUP_IDT(111)
    SETUP_IDT(112)
    SETUP_IDT(113)
    SETUP_IDT(114)
    SETUP_IDT(115)
    SETUP_IDT(116)
    SETUP_IDT(117)
    SETUP_IDT(118)
    SETUP_IDT(119)
    SETUP_IDT(120)
    SETUP_IDT(121)
    SETUP_IDT(122)
    SETUP_IDT(123)
    SETUP_IDT(124)
    SETUP_IDT(125)
    SETUP_IDT(126)
    SETUP_IDT(127)
    SETUP_IDT(128)
    SETUP_IDT(129)
    SETUP_IDT(130)
    SETUP_IDT(131)
    SETUP_IDT(132)
    SETUP_IDT(133)
    SETUP_IDT(134)
    SETUP_IDT(135)
    SETUP_IDT(136)
    SETUP_IDT(137)
    SETUP_IDT(138)
    SETUP_IDT(139)
    SETUP_IDT(140)
    SETUP_IDT(141)
    SETUP_IDT(142)
    SETUP_IDT(143)
    SETUP_IDT(144)
    SETUP_IDT(145)
    SETUP_IDT(146)
    SETUP_IDT(147)
    SETUP_IDT(148)
    SETUP_IDT(149)
    SETUP_IDT(150)
    SETUP_IDT(151)
    SETUP_IDT(152)
    SETUP_IDT(153)
    SETUP_IDT(154)
    SETUP_IDT(155)
    SETUP_IDT(156)
    SETUP_IDT(157)
    SETUP_IDT(158)
    SETUP_IDT(159)
    SETUP_IDT(160)
    SETUP_IDT(161)
    SETUP_IDT(162)
    SETUP_IDT(163)
    SETUP_IDT(164)
    SETUP_IDT(165)
    SETUP_IDT(166)
    SETUP_IDT(167)
    SETUP_IDT(168)
    SETUP_IDT(169)
    SETUP_IDT(170)
    SETUP_IDT(171)
    SETUP_IDT(172)
    SETUP_IDT(173)
    SETUP_IDT(174)
    SETUP_IDT(175)
    SETUP_IDT(176)
    SETUP_IDT(177)
    SETUP_IDT(178)
    SETUP_IDT(179)
    SETUP_IDT(180)
    SETUP_IDT(181)
    SETUP_IDT(182)
    SETUP_IDT(183)
    SETUP_IDT(184)
    SETUP_IDT(185)
    SETUP_IDT(186)
    SETUP_IDT(187)
    SETUP_IDT(188)
    SETUP_IDT(189)
    SETUP_IDT(190)
    SETUP_IDT(191)
    SETUP_IDT(192)
    SETUP_IDT(193)
    SETUP_IDT(194)
    SETUP_IDT(195)
    SETUP_IDT(196)
    SETUP_IDT(197)
    SETUP_IDT(198)
    SETUP_IDT(199)
    SETUP_IDT(200)
    SETUP_IDT(201)
    SETUP_IDT(202)
    SETUP_IDT(203)
    SETUP_IDT(204)
    SETUP_IDT(205)
    SETUP_IDT(206)
    SETUP_IDT(207)
    SETUP_IDT(208)
    SETUP_IDT(209)
    SETUP_IDT(210)
    SETUP_IDT(211)
    SETUP_IDT(212)
    SETUP_IDT(213)
    SETUP_IDT(214)
    SETUP_IDT(215)
    SETUP_IDT(216)
    SETUP_IDT(217)
    SETUP_IDT(218)
    SETUP_IDT(219)
    SETUP_IDT(220)
    SETUP_IDT(221)
    SETUP_IDT(222)
    SETUP_IDT(223)
    SETUP_IDT(224)
    SETUP_IDT(225)
    SETUP_IDT(226)
    SETUP_IDT(227)
    SETUP_IDT(228)
    SETUP_IDT(229)
    SETUP_IDT(230)
    SETUP_IDT(231)
    SETUP_IDT(232)
    SETUP_IDT(233)
    SETUP_IDT(234)
    SETUP_IDT(235)
    SETUP_IDT(236)
    SETUP_IDT(237)
    SETUP_IDT(238)
    SETUP_IDT(239)
    SETUP_IDT(240)
    SETUP_IDT(241)
    SETUP_IDT(242)
    SETUP_IDT(243)
    SETUP_IDT(244)
    SETUP_IDT(245)
    SETUP_IDT(246)
    SETUP_IDT(247)
    SETUP_IDT(248)
    SETUP_IDT(249)
    SETUP_IDT(250)
    SETUP_IDT(251)
    SETUP_IDT(252)
    SETUP_IDT(253)
    SETUP_IDT(254)
    SETUP_IDT(255)
    // lidt idt
    asm volatile("lidt %0" : : "m"(idt));
    asm volatile("sti\n");
}
