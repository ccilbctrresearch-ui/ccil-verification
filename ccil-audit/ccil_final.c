#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <assert.h>
typedef struct { int64_t pos; int64_t vel; } State;
typedef struct { int64_t decel; int64_t latency; } Params;
static int64_t imax(int64_t a, int64_t b) { return (a > b) ? a : b; }
static bool SD(const State *s, const Params *p) {
    int64_t lhs = s->pos * (2 * p->decel);
    int64_t rhs = s->vel * s->vel + 2 * p->latency * p->decel * s->vel;
    return lhs >= rhs;
}
static bool strongSD(const State *s, const Params *p) {
    int64_t lhs = s->pos * (2 * p->decel);
    int64_t rhs = s->vel * s->vel + 2 * p->latency * p->decel * s->vel + 2 * p->decel * s->vel;
    return lhs >= rhs;
}
static void ccil_step(const State *s, const Params *p, State *o) {
    if (strongSD(s, p)) { o->pos = s->pos - s->vel; o->vel = s->vel; }
    else { o->pos = s->pos - s->vel; o->vel = imax(0, s->vel - p->decel); }
}
void harness_continue(void) {
    State s; Params p;
    __CPROVER_assume(p.latency == 1);
    __CPROVER_assume(p.decel == 7000);
    __CPROVER_assume(s.vel >= 0 && s.vel <= 14000);
    __CPROVER_assume(s.pos >= 0 && s.pos <= 50000);
    __CPROVER_assume(SD(&s, &p));
    __CPROVER_assume(s.vel >= 0);
    __CPROVER_assume(s.pos >= s.vel);
    __CPROVER_assume(strongSD(&s, &p));
    State out; ccil_step(&s, &p, &out);
    assert(SD(&out, &p));
}
void harness_brake(void) {
    State s; Params p;
    __CPROVER_assume(p.latency == 1);
    __CPROVER_assume(p.decel == 7000);
    __CPROVER_assume(s.vel >= 0 && s.vel <= 14000);
    __CPROVER_assume(s.pos >= 0 && s.pos <= 50000);
    __CPROVER_assume(SD(&s, &p));
    __CPROVER_assume(s.vel >= 0);
    __CPROVER_assume(s.pos >= s.vel);
    __CPROVER_assume(!strongSD(&s, &p));
    State out; ccil_step(&s, &p, &out);
    assert(SD(&out, &p));
}
