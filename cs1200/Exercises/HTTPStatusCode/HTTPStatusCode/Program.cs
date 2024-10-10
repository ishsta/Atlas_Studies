﻿using System;

namespace HTTPStatusCode
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter a Response Code: ");

            int input = Convert.ToInt32(Console.ReadLine());

            switch (input) {
                case 100:
                case 101:
                case 102:
                case 103:
                    Console.WriteLine($"{input} is an Informational Response.");
                    break;
                case 200:
                case 201:
                case 202:
                case 203:
                case 204:
                case 205:
                case 206:
                case 207:
                case 208:
                case 226:
                    Console.WriteLine($"{input} is a Successful Response.");
                    break;
                case 300:
                case 301:
                case 302:
                case 303:
                case 304:
                case 305:
                case 306:
                case 307:
                case 308:
                    Console.WriteLine($"{input} is a Redirection Response.");
                    break;
                case 400:
                case 401:
                case 402:
                case 403:
                case 404:
                case 405:
                case 406:
                case 407:
                case 408:
                case 409:
                case 410:
                case 411:
                case 412:
                case 413:
                case 414:
                case 415:
                case 416:
                case 417:
                case 418:
                case 421:
                case 422:
                case 423:
                case 424:
                case 425:
                case 426:
                case 428:
                case 429:
                case 431:
                case 451:
                    Console.WriteLine($"{input} is a Client Error Response.");
                    break;
                case 500:
                case 501:
                case 502:
                case 503:
                case 504:
                case 505:
                case 506:
                case 507:
                case 508:
                case 510:
                case 511:
                    Console.WriteLine($"{input} is a Server Error Response.");
                    break;
                default:
                    Console.WriteLine($"{input} is not a valid Response.");
                    break;
            }
        }
    }
}