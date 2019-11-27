/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_net.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 15:35:35 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/27 18:16:56 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include_doom/doom.h"


struct          s_packet
{
    double      p_socket;
    double      p_life;
    double      p_join;
    double      p_request;
    int         p_disconnect;
    // etc
}               t_packet;




void    init_server()
{
    char        buf[255];
    IPaddress   ip;
    TCPsocket   tcpserver;
    int         n;
    
    if (SDLNet_Init() != 0)
    {
        ft_printf("INIT SERVER IMPOSSIBLE\n");
        return () // EXIT_FAILURE
    }
    if (SDLNet_ResolveHost(&ip, "**", **) != 0)
    {
        ft_printf("RESOLVE HOST IMPOSSIBLE\n");
        return () // EXIT_FAILURE
    }

    tcpserver = SDLNet_TCP_open(&ip);

    if (tcpserver == NULL)
    {
        ft_printf("ERREUR DE CONNECTION A L'IP\n");
        return () // EXIT_FAILURE
    }

    if ((n = SDLNet_TCP_Recv(tcpserver, buf, sizeof buf - 1)) <= 0)
    {
        printf("ERREUR DE RECEPTION : %s\n", SDLNet_GetError());
        return () // EXIT_FAILURE
    } 

    buf[n] = 0;
    printf("buf: %s\n", buf);

    if (SDLNet_TCP_Send(tcpserver, buf, n) < n)
    {
        printf("ERREUR D'ENVOI : %s\n", SDLNet_GetError());
        return () // EXIT_FAILURE
    }
    return (0);
}


switch ()
{
    case //
        return (ConstructPacket(JoinRequestPacket))
}