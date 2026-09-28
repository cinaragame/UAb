/* Interface modulo log */

#ifndef LOG_H
#define LOG_H

/* Comentario descritivo da função */
void Log_msg(const char *mensagem);
/* Comentario descritivo da função */
void Log_erro(const char *erro);
/* Comentario descritivo da função */
void Log_ativar(int estado); // 1 = ativo, 0 = inativo

#endif /* LOG_H */
