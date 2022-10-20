/*
===========================================================================
Copyright (C) 2022 Sergei Shubin

This file is part of Quake III Champions source code.

Quake III Champions source code is free software; you can redistribute it
published by the Free Software Foundation; either version 2 of the License,
or (at your option) any later version.

Quake III Champions source code is distributed in the hope that it will be
useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Quake III Champions source code; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
===========================================================================
*/
//
// bg_champions.c

#include "../qcommon/q_shared.h"
#include "bg_public.h"
#include "bg_local.h"
#include "bg_champions.h"

champion_stat_t champion_stats[NUM_CHAMPIONS] = {
    // sarge
    {
        100, // base_health
        100, // base_armor
        200, // max_health
        200, // max_armor
        30, // ability_cooldown
        -1, // ability_duration
        { // start_health
            100, // GT_FFA
            100, // GT_TOURNAMENT
            100, // GT_SINGLE_PLAYER
            100, // GT_TEAM
            100, // GT_TEAM2V2
            100, // GT_CTF
        },
        { // start_armor
            75, // GT_FFA
            0, // GT_TOURNAMENT
            0, // GT_SINGLE_PLAYER
            0, // GT_TEAM
            0, // GT_TEAM2V2
            0, // GT_CTF
        },
        { // spawn_protection
            0, // GT_FFA
            0, // GT_TOURNAMENT
            0, // GT_SINGLE_PLAYER
            0, // GT_TEAM
            0, // G_TEAM2V2
            0, // GT_CTF
        },
        320, // speed
        9999, // maxspeed
        { -15, -15, -24 }, // mins
        { 15, 15, 40 }, // maxs
    },
    // anarki
    {
        100, // base_health
        75, // base_armor
        150, // max_health
        150, // max_armor
        45, // ability_cooldown
        30, // tenths of a second // ability_duration
        { // start_health
            125, // GT_FFA
            125, // GT_TOURNAMENT
            100, // GT_SINGLE_PLAYER
            100, // G_TEAM2V2
            100, // GT_TEAM
            100, // GT_CTF
        },
        { // start_armor
            50, // GT_FFA
            0, // GT_TOURNAMENT
            0, // GT_SINGLE_PLAYER
            0, // GT_TEAM
            0, // GT_TEAM2V2
            0, // GT_CTF
        },
        { // spawn_protection
            0, // GT_FFA
            0, // GT_TOURNAMENT
            0, // GT_SINGLE_PLAYER
            0, // GT_TEAM
            0, // GT_TEAM2V2
            0, // GT_CTF
        },
        320, // speed
        640, // maxspeed
        { -12, -12, -24 }, // mins
        { 12, 12, 40 }, // maxs
    },
    // athena
    {
        100, // base_health
        100, // base_armor
        200, // max_health
        200, // max_armor
        30, // ability_cooldown
        -1, // ability_duration
        { // start_health
            100, // GT_FFA
            100, // GT_TOURNAMENT
            100, // GT_SINGLE_PLAYER
            100, // GT_TEAM
            100, // GT_TEAM2V2
            100, // GT_CTF
        },
        { // start_armor
            0, // GT_FFA
            0, // GT_TOURNAMENT
            0, // GT_SINGLE_PLAYER
            0, // GT_TEAM
            0, // GT_TEAM2V2
            0, // GT_CTF
        },
        { // spawn_protection
            0, // GT_FFA
            0, // GT_TOURNAMENT
            0, // GT_SINGLE_PLAYER
            0, // GT_TEAM
            0, // GT_TEAM2V2
            0, // GT_CTF
        },
        320, // speed
        1000, // maxspeed
        { -15, -15, -24 }, // mins
        { 15, 15, 32 }, // maxs
    },
    // nyx
    {
        100, // base_health
        100, // base_armor
        200, // max_health
        200, // max_armor
        30, // ability_cooldown
        -1, // ability_duration
        { // start_health
            100, // GT_FFA
            100, // GT_TOURNAMENT
            100, // GT_SINGLE_PLAYER
            100, // GT_TEAM
            100, // GT_TEAM2V2
            100, // GT_CTF
        },
        { // start_armor
            0, // GT_FFA
            0, // GT_TOURNAMENT
            0, // GT_SINGLE_PLAYER
            0, // GT_TEAM
            0, // GT_TEAM2V2
            0, // GT_CTF
        },
        { // spawn_protection
            0, // GT_FFA
            0, // GT_TOURNAMENT
            0, // GT_SINGLE_PLAYER
            0, // GT_TEAM
            0, // GT_TEAM2V2
            0, // GT_CTF
        },
        320, // speed
        1000, // maxspeed
        { -15, -15, -24 }, // mins
        { 15, 15, 32 }, // maxs
    },
    // slash
    {
        100, // base_health
        100, // base_armor
        200, // max_health
        200, // max_armor
        30, // ability_cooldown
        -1, // ability_duration
        { // start_health
            100, // GT_FFA
            100, // GT_TOURNAMENT
            100, // GT_SINGLE_PLAYER
            100, // GT_TEAM
            100, // GT_TEAM2V2
            100, // GT_CTF
        },
        { // start_armor
            0, // GT_FFA
            0, // GT_TOURNAMENT
            0, // GT_SINGLE_PLAYER
            0, // GT_TEAM
            0, // GT_TEAM2V2
            0, // GT_CTF
        },
        { // spawn_protection
            0, // GT_FFA
            0, // GT_TOURNAMENT
            0, // GT_SINGLE_PLAYER
            0, // GT_TEAM
            0, // GT_TEAM2V2
            0, // GT_CTF
        },
        320, // speed
        750, // maxspeed
        { -15, -15, -24 }, // mins
        { 15, 15, 32 }, // maxs
    },
    // bj
    {
        100, // base_health
        100, // base_armor
        200, // max_health
        200, // max_armor
        30, // ability_cooldown
        -1, // ability_duration
        { // start_health
            100, // GT_FFA
            100, // GT_TOURNAMENT
            100, // GT_SINGLE_PLAYER
            100, // GT_TEAM
            100, // GT_TEAM2V2
            100, // GT_CTF
        },
        { // start_armor
            0, // GT_FFA
            0, // GT_TOURNAMENT
            0, // GT_SINGLE_PLAYER
            0, // GT_TEAM
            0, // GT_TEAM2V2
            0, // GT_CTF
        },
        { // spawn_protection
            0, // GT_FFA
            0, // GT_TOURNAMENT
            0, // GT_SINGLE_PLAYER
            0, // GT_TEAM
            0, // GT_TEAM2V2
            0, // GT_CTF
        },
        310, // speed
        1000, // maxspeed
        { -15, -15, -24 }, // mins
        { 15, 15, 32 }, // maxs
    },
    // dk
    {
        100, // base_health
        100, // base_armor
        200, // max_health
        200, // max_armor
        30, // ability_cooldown
        -1, // ability_duration
        { // start_health
            100, // GT_FFA
            100, // GT_TOURNAMENT
            100, // GT_SINGLE_PLAYER
            100, // GT_TEAM
            100, // GT_TEAM2V2
            100, // GT_CTF
        },
        { // start_armor
            0, // GT_FFA
            0, // GT_TOURNAMENT
            0, // GT_SINGLE_PLAYER
            0, // GT_TEAM
            0, // GT_CTF
        },
        { // spawn_protection
            0, // GT_FFA
            0, // GT_TOURNAMENT
            0, // GT_SINGLE_PLAYER
            0, // GT_TEAM
            0, // GT_TEAM2V2
            0, // GT_CTF
        },
        310, // speed
        1000, // maxspeed
        { -15, -15, -24 }, // mins
        { 15, 15, 32 }, // maxs
    },
    // doomguy
    {
        100, // base_health
        100, // base_armor
        200, // max_health
        200, // max_armor
        30, // ability_cooldown
        -1, // ability_duration
        { // start_health
            100, // GT_FFA
            100, // GT_TOURNAMENT
            100, // GT_SINGLE_PLAYER
            100, // GT_TEAM
            100, // GT_TEAM2V2
            100, // GT_CTF
        },
        { // start_armor
            0, // GT_FFA
            0, // GT_TOURNAMENT
            0, // GT_SINGLE_PLAYER
            0, // GT_TEAM
            0, // GT_TEAM2V2
            0, // GT_CTF
        },
        { // spawn_protection
            0, // GT_FFA
            0, // GT_TOURNAMENT
            0, // GT_SINGLE_PLAYER
            0, // GT_TEAM
            0, // GT_TEAM2V2
            0, // GT_CTF
        },
        310, // speed
        1000, // maxspeed
        { -15, -15, -24 }, // mins
        { 15, 15, 32 }, // maxs
    },
    // eisen
    {
        100, // base_health
        100, // base_armor
        200, // max_health
        200, // max_armor
        30, // ability_cooldown
        -1, // ability_duration
        { // start_health
            100, // GT_FFA
            100, // GT_TOURNAMENT
            100, // GT_SINGLE_PLAYER
            100, // GT_TEAM
            100, // GT_TEAM2V2
            100, // GT_CTF
        },
        { // start_armor
            0, // GT_FFA
            0, // GT_TOURNAMENT
            0, // GT_SINGLE_PLAYER
            0, // GT_TEAM
            0, // GT_TEAM2V2
            0, // GT_CTF
        },
        { // spawn_protection
            0, // GT_FFA
            0, // GT_TOURNAMENT
            0, // GT_SINGLE_PLAYER
            0, // GT_TEAM
            0, // GT_TEAM2V2
            0, // GT_CTF
        },
        310, // speed
        1000, // maxspeed
        { -15, -15, -24 }, // mins
        { 15, 15, 32 }, // maxs
    },
    // galena
    {
        100, // base_health
        100, // base_armor
        200, // max_health
        200, // max_armor
        30, // ability_cooldown
        -1, // ability_duration
        { // start_health
            100, // GT_FFA
            100, // GT_TOURNAMENT
            100, // GT_SINGLE_PLAYER
            100, // GT_TEAM
            100, // GT_TEAM2V2
            100, // GT_CTF
        },
        { // start_armor
            0, // GT_FFA
            0, // GT_TOURNAMENT
            0, // GT_SINGLE_PLAYER
            0, // GT_TEAM
            0, // GT_TEAM2V2
            0, // GT_CTF
        },
        { // spawn_protection
            0, // GT_FFA
            0, // GT_TOURNAMENT
            0, // GT_SINGLE_PLAYER
            0, // GT_TEAM
            0, // GT_TEAM2V2
            0, // GT_CTF
        },
        310, // speed
        1000, // maxspeed
        { -15, -15, -24 }, // mins
        { 15, 15, 32 }, // maxs
    },
    // ranger
    {
        100, // base_health
        100, // base_armor
        175, // max_health
        150, // max_armor
        45, // ability_cooldown
        -1, // ability_duration
        { // start_health
            125, // GT_FFA
            125, // GT_TOURNAMENT
            100, // GT_SINGLE_PLAYER
            100, // GT_TEAM
            100, // GT_TEAM2V2
            100, // GT_CTF
        },
        { // start_armor
            50, // GT_FFA
            50, // GT_TOURNAMENT
            0, // GT_SINGLE_PLAYER
            0, // GT_TEAM
            0, // GT_TEAM2V2
            0, // GT_CTF
        },
        { // spawn_protection
            0, // GT_FFA
            0, // GT_TOURNAMENT
            0, // GT_SINGLE_PLAYER
            0, // GT_TEAM
            0, // GT_TEAM2V2
            0, // GT_CTF
        },
        310, // speed
        1000, // maxspeed
        { -15, -15, -24 }, // mins
        { 15, 15, 40 }, // maxs
    },
    // strogg
    {
        100, // base_health
        100, // base_armor
        200, // max_health
        200, // max_armor
        30, // ability_cooldown
        -1, // ability_duration
        { // start_health
            100, // GT_FFA
            100, // GT_TOURNAMENT
            100, // GT_SINGLE_PLAYER
            100, // GT_TEAM
            100, // GT_TEAM2V2
            100, // GT_CTF
        },
        { // start_armor
            0, // GT_FFA
            0, // GT_TOURNAMENT
            0, // GT_SINGLE_PLAYER
            0, // GT_TEAM
            0, // GT_CTF
        },
        { // spawn_protection
            0, // GT_FFA
            0, // GT_TOURNAMENT
            0, // GT_SINGLE_PLAYER
            0, // GT_TEAM
            0, // GT_TEAM2V2
            0, // GT_CTF
        },
        310, // speed
        750, // maxspeed
        { -15, -15, -24 }, // mins
        { 15, 15, 32 }, // maxs
    },
    // visor
    {
        100, // base_health
        100, // base_armor
        200, // max_health
        200, // max_armor
        30, // ability_cooldown
        -1, // ability_duration
        { // start_health
            100, // GT_FFA
            100, // GT_TOURNAMENT
            100, // GT_SINGLE_PLAYER
            100, // GT_TEAM
            100, // GT_TEAM2V2
            100, // GT_CTF
        },
        { // start_armor
            0, // GT_FFA
            0, // GT_TOURNAMENT
            0, // GT_SINGLE_PLAYER
            0, // GT_TEAM
            0, // GT_TEAM2V2
            0, // GT_CTF
        },
        { // spawn_protection
            0, // GT_FFA
            0, // GT_TOURNAMENT
            0, // GT_SINGLE_PLAYER
            0, // GT_TEAM
            0, // GT_TEAM2V2
            0, // GT_CTF
        },
        320, // speed
        2000, // maxspeed
        { -15, -15, -24 }, // mins
        { 15, 15, 32 }, // maxs
    },
    // clutch
    {
        100, // base_health
        100, // base_armor
        200, // max_health
        200, // max_armor
        30, // ability_cooldown
        -1, // ability_duration
        { // start_health
            100, // GT_FFA
            100, // GT_TOURNAMENT
            100, // GT_SINGLE_PLAYER
            100, // GT_TEAM
            100, // GT_TEAM2V2
            100, // GT_CTF
        },
        { // start_armor
            0, // GT_FFA
            0, // GT_TOURNAMENT
            0, // GT_SINGLE_PLAYER
            0, // GT_TEAM
            0, // GT_TEAM2V2
            0, // GT_CTF
        },
        { // spawn_protection
            0, // GT_FFA
            0, // GT_TOURNAMENT
            0, // GT_SINGLE_PLAYER
            0, // GT_TEAM
            0, // GT_TEAM2V2
            0, // GT_CTF
        },
        300, // speed
        1000, // maxspeed
        { -15, -15, -24 }, // mins
        { 15, 15, 32 }, // maxs
    },
    // keel
    {
        100, // base_health
        125, // base_armor
        175, // max_health
        175, // max_armor
        45, // ability_cooldown
        -1, // ability_duration
        { // start_health
            125, // GT_FFA
            125, // GT_TOURNAMENT
            125, // GT_SINGLE_PLAYER
            125, // GT_TEAM
            125, // GT_TEAM2V2
            125, // GT_CTF
        },
        { // start_armor
            100, // GT_FFA
            100, // GT_TOURNAMENT
            0, // GT_SINGLE_PLAYER
            0, // GT_TEAM
            0, // GT_TEAM2V2
            0, // GT_CTF
        },
        { // spawn_protection
            0, // GT_FFA
            0, // GT_TOURNAMENT
            0, // GT_SINGLE_PLAYER
            0, // GT_TEAM
            0, // GT_TEAM2V2
            0, // GT_CTF
        },
        300, // speed
        1000, // maxspeed
        { -15, -15, -24 }, // mins
        { 15, 15, 40 }, // maxs
    },
    // scalebearer
    {
        100, // base_health
        100, // base_armor
        200, // max_health
        200, // max_armor
        30, // ability_cooldown
        -1, // ability_duration
        { // start_health
            100, // GT_FFA
            100, // GT_TOURNAMENT
            100, // GT_SINGLE_PLAYER
            100, // GT_TEAM
            100, // GT_TEAM2V2
            100, // GT_CTF
        },
        { // start_armor
            0, // GT_FFA
            0, // GT_TOURNAMENT
            0, // GT_SINGLE_PLAYER
            0, // GT_TEAM
            0, // GT_TEAM2V2
            0, // GT_CTF
        },
        { // spawn_protection
            0, // GT_FFA
            0, // GT_TOURNAMENT
            0, // GT_SINGLE_PLAYER
            0, // GT_TEAM
            0, // GT_TEAM2V2
            0, // GT_CTF
        },
        300, // speed
        1000, // maxspeed
        { -18, -18, -24 }, // mins
        { 18, 18, 32 }, // maxs
    },
    // sorlag
    {
        100, // base_health
        100, // base_armor
        200, // max_health
        200, // max_armor
        30, // ability_cooldown
        -1, // ability_duration
        { // start_health
            100, // GT_FFA
            100, // GT_TOURNAMENT
            100, // GT_SINGLE_PLAYER
            100, // GT_TEAM
            100, // GT_TEAM2V2
            100, // GT_CTF
        },
        { // start_armor
            0, // GT_FFA
            0, // GT_TOURNAMENT
            0, // GT_SINGLE_PLAYER
            0, // GT_TEAM
            0, // GT_TEAM2V2
            0, // GT_CTF
        },
        { // spawn_protection
            0, // GT_FFA
            0, // GT_TOURNAMENT
            0, // GT_SINGLE_PLAYER
            0, // GT_TEAM
            0, // GT_TEAM2V2
            0, // GT_CTF
        },
        300, // speed
        750, // maxspeed
        { -15, -15, -24 }, // mins
        { 15, 15, 32 }, // maxs
    },
};

char *champion_names[NUM_CHAMPIONS] = {
    "sarge",
    "anarki",
    "athena",
    "nyx",
    "slash",
    "bj",
    "dk",
    "doom",
    "eisen",
    "galena",
    "ranger",
    "strogg",
    "visor",
    "clutch",
    "keel",
    "scalebearer",
    "sorlag",
};

char* champion_models[NUM_CHAMPIONS] = {
    "sarge",  // sarge
    "anarki", // anarki
    "hunter", // athena
    "mynx",   // nyx
    "slash",  // slash
    "bitterman",  // bj
    "klesk",  // dk
    "doom",   // doom
    "razor",  // eisen
    "major",  // galena
    "ranger", // ranger
    "grunt",  // strogg
    "visor",  // visor
    "tankjr", // clutch
    "keel",   // keel
    "biker",  // scalebearer
    "sorlag", // sorlag
};

char* champion_skins[NUM_CHAMPIONS] = {
    "pm", // sarge
    "pm", // anarki
    "pm", // athena
    "pm", // nyx
    "pm", // slash
    "pm", // bj
    "pm", // dk
    "pm", // doom
    "pm", // eisen
    "pm", // galena
    "pm", // ranger
    "pm", // strogg
    "pm", // visor
    "pm", // clutch
    "pm", // keel
    "pm", // scalebearer
    "pm", // sorlag
};

int ParseChampionName( const char* name ) {
    int i;
    for ( i = 0; i < NUM_CHAMPIONS; i++ ) {
        if ( !Q_stricmp( name, champion_names[i] ) ) {
            return i;
        }
    }
    return CHAMP_SARGE;
}

int ParseStartingWeapon( const char *name ) {
    if ( !Q_stricmp( name, "sg") || !Q_stricmp( name, "shotgun" ) ) {
        return WP_LOUSY_SHOTGUN;
    }
    if ( !Q_stricmp( name, "pg") || !Q_stricmp( name, "plasmagun" ) || !Q_stricmp( name, "plasma" ) ) {
        return WP_LOUSY_PLASMAGUN;
    }
    return WP_LOUSY_MACHINEGUN;
}
