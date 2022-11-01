#ifndef ALLITEMS_h
#define ALLITEMS_h
#include <iostream>
#include <string>
#include "items.h"
using namespace std;


// weapons - 7
// helmets - 7
// chestplates - 7
// leggings - 7
// boots - 8


// Legendary Items
Weapon LichsSword = Weapon(
    2, 1250, // id cost
    380, // damage
    "legendary", // rare
    "Ледяная Скорбь", // name 
    "Всякий, кто завладеет этим клинком, получит вечную власть. Подобно тому как лезвие разрушает плоть, сила уродует душу"
); //


Weapon WayfinderCrossbow = Weapon(
    3, 1337, // id cost
    320, // damage
    "legendary", // rare
    "Арбалет путеискателя", // name 
    "Его острая стрела способна пронзить что угодно, даже сталь"
); //


Helmet HelmOfDomination = Helmet(
    2, 1340, // id cost
    20, 1, 25, // protection regeneration damage_boost
    "legendary", // rare
    "Шлем Господства", // name
    "Был создан в Кузне Господства демонами Пылающего Легиона"
);  //


Helmet AzeriteHelm = Helmet(
    3, 850, // id cost
    35, 0, 0, // protection regeneration damage_boost
    "legendary", // rare
    "Азеритовый шлем", // name
    "Живой символ надежды, который носят защитники умирающей планеты. Судьбу Азерот разделят все ее дети"
); //


Chestplate Mantle = Chestplate(
    2, 1100, // id cost
    20, 40, 0, // protection regeneration damage_boost
    "legendary", // rare
    "Мантия Ашжра'камас, Покров Решимости", // name
    "Все что находится под мантией приходит в порядок, восстанавливается"
); //


Chestplate DiamondChestplate = Chestplate(
    3, 1570, // id cost
    45, 0, 0, // protection regeneration damage_boost
    "legendary", // rare
    "Алмазный нагрудник", // name
    "Сияет ярко - защищиет хорошо"
); //


Leggings PiercingLeggings = Leggings(
    2, 1111, // id cost
    17, 0, 15, // protection regeneration damage_boost
    "legendary", // rare
    "Колючие Поножи", // name
    "Поножи полностью покрытые иголками, трогать их не стоит"
); //


Leggings Bloomers = Leggings(
    3, 960, // id cost
    15, 9, 2, // protection regeneration damage_boost
    "legendary", // rare
    "Шаровары", // name
    "Больше свободы - больше движения"
); // 


Boots BootsOfRebirth = Boots(
    2, 670, // id cost
    35, 2, 15, // protection regeneration damage_boost
    "legendary", // rare
    "Сапоги перерождения", // name
    "Новый шаг - новый поворот, что он нам несет?"
); //


Boots LucifersBerets = Boots(
    3, 666, // id cost
    6, 6, 6, // protection regeneration damage_boost
    "legendary", // rare
    "Берцы Льва Юрьевича Цифера", // name
    "Ранее принадлежали некому Л.Ю. Циферу, в них есть что-то загадочное"
); //


// Items --------------------------------------------------------------------------------
Weapon Punch = Weapon(
    0, 0, // id cost
    15, // damage
    "default", // rare
    "Кулаки", // name 
    "Обычные кулаки, есть у каждого человека\nБольше силы - больше пользы"
); //


Weapon Stick = Weapon(
    4, 10, // id cost
    20, // damage
    "default", // rare
    "Палка", // name 
    "Длинная и деревянная"
); //


Weapon Bow = Weapon(
    5, 100, // id cost
    45, // damage
    "rare", // rare
    "Лук", // name 
    "Лучшая битва - битва на расстоянии"
); //


Weapon BerserkSword = Weapon(
    6, 450, // id cost
    140, // damage
    "epic", // rare
    "Меч берсерка", // name 
    "Чрезвычайно длинный и тяжёлый клинок с лёгкостью способный за один взмах разрубить нескольких человек в латных доспехах"
); //


Helmet Hat = Helmet(
    1, 35,  // id cost
    2, 0, 0, // protection regeneration damage_boost
    "default", // rare
    "Шляпа", // name
    ""
); //


Helmet Pot = Helmet(
    4, 35, // id cost
    3, 0, 0, // protection regeneration damage_boost
    "default", // rare
    "Кастрюля", // name
    ""
); //


Helmet DovakinsHelm = Helmet(
    5, 100, // id cost
    7, 2, 3, // protection regeneration damage_boost
    "rare", // rare
    "Шлем Довакина", // name
    "Когда-то его носил драконорожденный"
); //


Helmet Kasa = Helmet(
    6, 450, // id cost
    15, 1, 3, // protection regeneration damage_boost
    "epic", // rare
    "Железная каса ронина", // name
    "Мужчина, которого некогда звали Юра, был глубоко предан своей возлюбленной"
); //


Chestplate Jacket = Chestplate(
    1, 40, // id cost
    4, 0, 0, // protection regeneration damage_boost
    "default", // rare
    "Куртка", // name
    "Джинсовая куртка"
); //


Chestplate LeatherJacket = Chestplate(
    4, 50, // id cost
    6, 0, 2, // protection regeneration damage_boost
    "default", // rare
    "Кожанка", // name
    "Такая же как и у Т-800"
); //


Chestplate MagicCape = Chestplate(
    5, 85, // id cost
    15, 2, 1, // protection regeneration damage_boost
    "rare", // rare
    "Магическая накидка", // name
    "От нее исходит завораживающая аура"
); //


Chestplate ChainmailPlate = Chestplate(
    6, 800, // id cost
    25, 0, 4, // protection regeneration damage_boost
    "epic", // rare
    "Кольчужный нагрудник", // name
    "Был создан в кузнеце из пламени"
); //


Leggings Pants = Leggings(
    1, 45, // id cost
    4, 0, 0, // protection regeneration damage_boost
    "default", // rare
    "Джинсы", // name
    "Тоже джинсовые"
); //


Leggings Kilt = Leggings(
    4, 55, // id cost
    5, 0, 1, // protection regeneration damage_boost
    "default", // rare
    "Килт", // name
    "НЕ ЮБКА"
); //


Leggings IronLeggings = Leggings(
    5, 80, // id cost
    10, 0, 1, // protection regeneration damage_boost
    "rare", // rare
    "Железные поножи", // name
    "Поножи с большими железными вставками"
); //


Leggings ScalyLegArmor = Leggings(
    6, 700, // id cost
    20, 4, 4, // protection regeneration damage_boost
    "epic", // rare
    "Чешуйчатые ножные латы", // name
    "Напоминают железного ящера"
); //


Boots Shoes = Boots(
    1, 40, // id cost
    3, 0, 0, // protection regeneration damage_boost
    "default", // rare
    "Ботинки", // name
    ""
); //


Boots Slippers = Boots(
    4, 40, // id cost
    5, 0, 0, // protection regeneration damage_boost
    "default", // rare
    "Тапки", // name
    "В них удобно..."
); //


Boots TacticBoots = Boots(
    5, 40, // id cost
    10, 1, 1, // protection regeneration damage_boost
    "rare", // rare
    "Тактические ботинки", // name
    "В них удобно планировать бой"
); //


Boots ElectricBoots = Boots(
    6, 220, // id cost
    14, 0, 7, // protection regeneration damage_boost
    "epic", // rare
    "Электро ботинки", // name
    "Лучше их не трогать"
); //


Boots ReinforcedBoots = Boots(
    7, 200, // id cost
    18, 0, 2, // protection regeneration damage_boost
    "epic", // rare
    "Усиленные ботфорты", // name
    "Крепкая боевая обувь"
); //


// NoItems
Weapon NoWeapon = Punch;


Helmet NoHelmet = Helmet(
    0, 0, // id cost
    0, 0, 0, // damage
    "default", // rare
    "Ничего", // name 
    ""
);


Chestplate NoChestplate = Chestplate(
    0, 0, // id cost
    0, 0, 0, // damage
    "default", // rare
    "Ничего", // name 
    ""
);


Leggings NoLeggings = Leggings(
    0, 0, // id cost
    0, 0, 0, // damage
    "default", // rare
    "Ничего", // name 
    ""
);


Boots NoBoots = Boots(
    0, 0, // id cost
    0, 0, 0, // damage
    "default", // rare
    "Ничего", // name 
    ""
);



#endif
