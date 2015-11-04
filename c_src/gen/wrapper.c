#include "../runtime/api.h"
#include "erl_nif.h"
#include <string.h>

#include "danish.h"

#include "dutch.h"

#include "english.h"

#include "finnish.h"

#include "french.h"

#include "german.h"

#include "german2.h"

#include "hungarian.h"

#include "italian.h"

#include "kraaij_pohlmann.h"

#include "lovins.h"

#include "norwegian.h"

#include "portuguese.h"

#include "romanian.h"

#include "russian.h"

#include "spanish.h"

#include "swedish.h"

#include "turkish.h"



static ERL_NIF_TERM stem_danish_nif(ErlNifEnv* erl_env, int argc, const ERL_NIF_TERM argv[]){
    struct SN_env * env;
    ErlNifBinary in_binary;
    ErlNifBinary final_binary;
    if (!enif_inspect_binary(erl_env, argv[0], &in_binary)) {
        return enif_make_badarg(erl_env);
    }
    env = danish_create_env();
    SN_set_current(env,in_binary.size,in_binary.data);
    danish_stem(env);
    enif_alloc_binary(env->l,&final_binary);
    memcpy(final_binary.data,env->p,env->l);
    danish_close_env(env);
    return enif_make_binary(erl_env,&final_binary);
}

static ERL_NIF_TERM stem_dutch_nif(ErlNifEnv* erl_env, int argc, const ERL_NIF_TERM argv[]){
    struct SN_env * env;
    ErlNifBinary in_binary;
    ErlNifBinary final_binary;
    if (!enif_inspect_binary(erl_env, argv[0], &in_binary)) {
        return enif_make_badarg(erl_env);
    }
    env = dutch_create_env();
    SN_set_current(env,in_binary.size,in_binary.data);
    dutch_stem(env);
    enif_alloc_binary(env->l,&final_binary);
    memcpy(final_binary.data,env->p,env->l);
    dutch_close_env(env);
    return enif_make_binary(erl_env,&final_binary);
}

static ERL_NIF_TERM stem_english_nif(ErlNifEnv* erl_env, int argc, const ERL_NIF_TERM argv[]){
    struct SN_env * env;
    ErlNifBinary in_binary;
    ErlNifBinary final_binary;
    if (!enif_inspect_binary(erl_env, argv[0], &in_binary)) {
        return enif_make_badarg(erl_env);
    }
    env = english_create_env();
    SN_set_current(env,in_binary.size,in_binary.data);
    english_stem(env);
    enif_alloc_binary(env->l,&final_binary);
    memcpy(final_binary.data,env->p,env->l);
    english_close_env(env);
    return enif_make_binary(erl_env,&final_binary);
}

static ERL_NIF_TERM stem_finnish_nif(ErlNifEnv* erl_env, int argc, const ERL_NIF_TERM argv[]){
    struct SN_env * env;
    ErlNifBinary in_binary;
    ErlNifBinary final_binary;
    if (!enif_inspect_binary(erl_env, argv[0], &in_binary)) {
        return enif_make_badarg(erl_env);
    }
    env = finnish_create_env();
    SN_set_current(env,in_binary.size,in_binary.data);
    finnish_stem(env);
    enif_alloc_binary(env->l,&final_binary);
    memcpy(final_binary.data,env->p,env->l);
    finnish_close_env(env);
    return enif_make_binary(erl_env,&final_binary);
}

static ERL_NIF_TERM stem_french_nif(ErlNifEnv* erl_env, int argc, const ERL_NIF_TERM argv[]){
    struct SN_env * env;
    ErlNifBinary in_binary;
    ErlNifBinary final_binary;
    if (!enif_inspect_binary(erl_env, argv[0], &in_binary)) {
        return enif_make_badarg(erl_env);
    }
    env = french_create_env();
    SN_set_current(env,in_binary.size,in_binary.data);
    french_stem(env);
    enif_alloc_binary(env->l,&final_binary);
    memcpy(final_binary.data,env->p,env->l);
    french_close_env(env);
    return enif_make_binary(erl_env,&final_binary);
}

static ERL_NIF_TERM stem_german_nif(ErlNifEnv* erl_env, int argc, const ERL_NIF_TERM argv[]){
    struct SN_env * env;
    ErlNifBinary in_binary;
    ErlNifBinary final_binary;
    if (!enif_inspect_binary(erl_env, argv[0], &in_binary)) {
        return enif_make_badarg(erl_env);
    }
    env = german_create_env();
    SN_set_current(env,in_binary.size,in_binary.data);
    german_stem(env);
    enif_alloc_binary(env->l,&final_binary);
    memcpy(final_binary.data,env->p,env->l);
    german_close_env(env);
    return enif_make_binary(erl_env,&final_binary);
}

static ERL_NIF_TERM stem_german2_nif(ErlNifEnv* erl_env, int argc, const ERL_NIF_TERM argv[]){
    struct SN_env * env;
    ErlNifBinary in_binary;
    ErlNifBinary final_binary;
    if (!enif_inspect_binary(erl_env, argv[0], &in_binary)) {
        return enif_make_badarg(erl_env);
    }
    env = german2_create_env();
    SN_set_current(env,in_binary.size,in_binary.data);
    german2_stem(env);
    enif_alloc_binary(env->l,&final_binary);
    memcpy(final_binary.data,env->p,env->l);
    german2_close_env(env);
    return enif_make_binary(erl_env,&final_binary);
}

static ERL_NIF_TERM stem_hungarian_nif(ErlNifEnv* erl_env, int argc, const ERL_NIF_TERM argv[]){
    struct SN_env * env;
    ErlNifBinary in_binary;
    ErlNifBinary final_binary;
    if (!enif_inspect_binary(erl_env, argv[0], &in_binary)) {
        return enif_make_badarg(erl_env);
    }
    env = hungarian_create_env();
    SN_set_current(env,in_binary.size,in_binary.data);
    hungarian_stem(env);
    enif_alloc_binary(env->l,&final_binary);
    memcpy(final_binary.data,env->p,env->l);
    hungarian_close_env(env);
    return enif_make_binary(erl_env,&final_binary);
}

static ERL_NIF_TERM stem_italian_nif(ErlNifEnv* erl_env, int argc, const ERL_NIF_TERM argv[]){
    struct SN_env * env;
    ErlNifBinary in_binary;
    ErlNifBinary final_binary;
    if (!enif_inspect_binary(erl_env, argv[0], &in_binary)) {
        return enif_make_badarg(erl_env);
    }
    env = italian_create_env();
    SN_set_current(env,in_binary.size,in_binary.data);
    italian_stem(env);
    enif_alloc_binary(env->l,&final_binary);
    memcpy(final_binary.data,env->p,env->l);
    italian_close_env(env);
    return enif_make_binary(erl_env,&final_binary);
}

static ERL_NIF_TERM stem_kraaij_pohlmann_nif(ErlNifEnv* erl_env, int argc, const ERL_NIF_TERM argv[]){
    struct SN_env * env;
    ErlNifBinary in_binary;
    ErlNifBinary final_binary;
    if (!enif_inspect_binary(erl_env, argv[0], &in_binary)) {
        return enif_make_badarg(erl_env);
    }
    env = kraaij_pohlmann_create_env();
    SN_set_current(env,in_binary.size,in_binary.data);
    kraaij_pohlmann_stem(env);
    enif_alloc_binary(env->l,&final_binary);
    memcpy(final_binary.data,env->p,env->l);
    kraaij_pohlmann_close_env(env);
    return enif_make_binary(erl_env,&final_binary);
}

static ERL_NIF_TERM stem_lovins_nif(ErlNifEnv* erl_env, int argc, const ERL_NIF_TERM argv[]){
    struct SN_env * env;
    ErlNifBinary in_binary;
    ErlNifBinary final_binary;
    if (!enif_inspect_binary(erl_env, argv[0], &in_binary)) {
        return enif_make_badarg(erl_env);
    }
    env = lovins_create_env();
    SN_set_current(env,in_binary.size,in_binary.data);
    lovins_stem(env);
    enif_alloc_binary(env->l,&final_binary);
    memcpy(final_binary.data,env->p,env->l);
    lovins_close_env(env);
    return enif_make_binary(erl_env,&final_binary);
}

static ERL_NIF_TERM stem_norwegian_nif(ErlNifEnv* erl_env, int argc, const ERL_NIF_TERM argv[]){
    struct SN_env * env;
    ErlNifBinary in_binary;
    ErlNifBinary final_binary;
    if (!enif_inspect_binary(erl_env, argv[0], &in_binary)) {
        return enif_make_badarg(erl_env);
    }
    env = norwegian_create_env();
    SN_set_current(env,in_binary.size,in_binary.data);
    norwegian_stem(env);
    enif_alloc_binary(env->l,&final_binary);
    memcpy(final_binary.data,env->p,env->l);
    norwegian_close_env(env);
    return enif_make_binary(erl_env,&final_binary);
}

static ERL_NIF_TERM stem_portuguese_nif(ErlNifEnv* erl_env, int argc, const ERL_NIF_TERM argv[]){
    struct SN_env * env;
    ErlNifBinary in_binary;
    ErlNifBinary final_binary;
    if (!enif_inspect_binary(erl_env, argv[0], &in_binary)) {
        return enif_make_badarg(erl_env);
    }
    env = portuguese_create_env();
    SN_set_current(env,in_binary.size,in_binary.data);
    portuguese_stem(env);
    enif_alloc_binary(env->l,&final_binary);
    memcpy(final_binary.data,env->p,env->l);
    portuguese_close_env(env);
    return enif_make_binary(erl_env,&final_binary);
}

static ERL_NIF_TERM stem_romanian_nif(ErlNifEnv* erl_env, int argc, const ERL_NIF_TERM argv[]){
    struct SN_env * env;
    ErlNifBinary in_binary;
    ErlNifBinary final_binary;
    if (!enif_inspect_binary(erl_env, argv[0], &in_binary)) {
        return enif_make_badarg(erl_env);
    }
    env = romanian_create_env();
    SN_set_current(env,in_binary.size,in_binary.data);
    romanian_stem(env);
    enif_alloc_binary(env->l,&final_binary);
    memcpy(final_binary.data,env->p,env->l);
    romanian_close_env(env);
    return enif_make_binary(erl_env,&final_binary);
}

static ERL_NIF_TERM stem_russian_nif(ErlNifEnv* erl_env, int argc, const ERL_NIF_TERM argv[]){
    struct SN_env * env;
    ErlNifBinary in_binary;
    ErlNifBinary final_binary;
    if (!enif_inspect_binary(erl_env, argv[0], &in_binary)) {
        return enif_make_badarg(erl_env);
    }
    env = russian_create_env();
    SN_set_current(env,in_binary.size,in_binary.data);
    russian_stem(env);
    enif_alloc_binary(env->l,&final_binary);
    memcpy(final_binary.data,env->p,env->l);
    russian_close_env(env);
    return enif_make_binary(erl_env,&final_binary);
}

static ERL_NIF_TERM stem_spanish_nif(ErlNifEnv* erl_env, int argc, const ERL_NIF_TERM argv[]){
    struct SN_env * env;
    ErlNifBinary in_binary;
    ErlNifBinary final_binary;
    if (!enif_inspect_binary(erl_env, argv[0], &in_binary)) {
        return enif_make_badarg(erl_env);
    }
    env = spanish_create_env();
    SN_set_current(env,in_binary.size,in_binary.data);
    spanish_stem(env);
    enif_alloc_binary(env->l,&final_binary);
    memcpy(final_binary.data,env->p,env->l);
    spanish_close_env(env);
    return enif_make_binary(erl_env,&final_binary);
}

static ERL_NIF_TERM stem_swedish_nif(ErlNifEnv* erl_env, int argc, const ERL_NIF_TERM argv[]){
    struct SN_env * env;
    ErlNifBinary in_binary;
    ErlNifBinary final_binary;
    if (!enif_inspect_binary(erl_env, argv[0], &in_binary)) {
        return enif_make_badarg(erl_env);
    }
    env = swedish_create_env();
    SN_set_current(env,in_binary.size,in_binary.data);
    swedish_stem(env);
    enif_alloc_binary(env->l,&final_binary);
    memcpy(final_binary.data,env->p,env->l);
    swedish_close_env(env);
    return enif_make_binary(erl_env,&final_binary);
}

static ERL_NIF_TERM stem_turkish_nif(ErlNifEnv* erl_env, int argc, const ERL_NIF_TERM argv[]){
    struct SN_env * env;
    ErlNifBinary in_binary;
    ErlNifBinary final_binary;
    if (!enif_inspect_binary(erl_env, argv[0], &in_binary)) {
        return enif_make_badarg(erl_env);
    }
    env = turkish_create_env();
    SN_set_current(env,in_binary.size,in_binary.data);
    turkish_stem(env);
    enif_alloc_binary(env->l,&final_binary);
    memcpy(final_binary.data,env->p,env->l);
    turkish_close_env(env);
    return enif_make_binary(erl_env,&final_binary);
}


static ErlNifFunc nif_funcs[] = {

  {"danish", 1, stem_danish_nif},

  {"dutch", 1, stem_dutch_nif},

  {"english", 1, stem_english_nif},

  {"finnish", 1, stem_finnish_nif},

  {"french", 1, stem_french_nif},

  {"german", 1, stem_german_nif},

  {"german2", 1, stem_german2_nif},

  {"hungarian", 1, stem_hungarian_nif},

  {"italian", 1, stem_italian_nif},

  {"kraaij_pohlmann", 1, stem_kraaij_pohlmann_nif},

  {"lovins", 1, stem_lovins_nif},

  {"norwegian", 1, stem_norwegian_nif},

  {"portuguese", 1, stem_portuguese_nif},

  {"romanian", 1, stem_romanian_nif},

  {"russian", 1, stem_russian_nif},

  {"spanish", 1, stem_spanish_nif},

  {"swedish", 1, stem_swedish_nif},

  {"turkish", 1, stem_turkish_nif},

};

ERL_NIF_INIT(Elixir.Stemex,nif_funcs, NULL, NULL, NULL, NULL)
