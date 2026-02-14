/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarti2 <romarti2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:43:54 by romarti2          #+#    #+#             */
/*   Updated: 2026/02/14 21:10:53 by romarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	(del)(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	*lst = NULL;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}


t_list	*ft_lstnew(void *content)
{
	t_list	*l;

	l = malloc(sizeof(t_list));
	if (!l)
		return (NULL);
	l->content = content;
	l->next = NULL;
	return (l);
}

 char *rest (char *acum)
{
    int i;
    char    *res;

    if (!acum)
        return (NULL);    
    i = 0;
    while (acum[i] && acum[i] != '\n')
        i++;
    if (!acum[i]) // En caso de llegar al final sin \n
    {
        free(acum);
        return (NULL);
    }
    res = ft_strdup(acum + i + 1); // copiar lo ue hay dsps de \n
    free(acum);
    return (res);
}
    
char *extract_line (char *acum)
{
    int i;
    char *line;

    i = 0;
    if (!acum || !*acum)
        return NULL;
    while (acum[i] && acum[i] != '\n')
        i++;
    if (acum[i] == '\n')
        i++;
    line = ft_substr(acum, 0, i);
    return (line);   
}

char *get_next_line(int fd)
{
    char buf[BUFFER_SIZE + 1];
    ssize_t nbytes;
    static char *acum;
    char *line;
    char *tmp;

    if (fd <0 || BUFFER_SIZE <= 0)
        return (NULL);
    nbytes = 1; // para que while arranque la primera vez.
    while (!(acum && ft_strchr (acum, '\n')) && (nbytes = read(fd, buf, BUFFER_SIZE)) > 0)
    {
        buf[nbytes] = '\0';
        if (!acum)
            acum = ft_strdup("");
        tmp = ft_strjoin(acum, buf);
        free(acum);
        acum = tmp;
    }       
    if (nbytes < 0)
    {
        free (acum);
        return (acum = NULL);
    }
    line = extract_line (acum);
    acum = rest(acum);
    return (line);
}
t_list *get_txt(int fd)
{
   t_list *txt = NULL;
   t_list *tmp;
   char *line;
   
    while ((line = get_next_line (fd)) != NULL)
    {
      tmp = ft_lstnew(line);
      if (!tmp)
      {
        free (line);
        ft_lstclear (&txt, free);
        return (NULL);
      }
        ft_lstadd_back (&txt, tmp);
    }
    return(txt);  
}

int main(void)
{
    int     fd;
    char    *pathname;
    t_list  *txt;
    t_list  *curr; // Puntero auxiliar para recorrer

    pathname = "/home/romarti2/Curso42/Git Hub/get_next_line/fichero";
    fd = open(pathname, O_RDONLY);
    if (fd == -1)
    {
        printf("Error al abrir el archivo");
        return (1);
    }
    txt = get_txt(fd);
    curr = txt;
    while (curr)
    {
        printf("%s", (char *)(curr->content));
        curr = curr->next;
    }
    close(fd);
    ft_lstclear(&txt, free); 
    return (0);
}